package com.agilysys.digitalkey

import android.app.Activity
import android.content.Context
import android.util.Log
import com.zaplox.zdk.*
import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import kotlinx.coroutines.runBlocking


/** DigitalkeyPlugin */
class DigitalkeyPlugin : FlutterPlugin, MethodCallHandler, ActivityAware {
    /// The MethodChannel that will the communication between Flutter and native Android
    ///
    /// This local reference serves to register the plugin with the Flutter Engine and unregister it
    /// when the Flutter Engine is detached from the Activity
    private lateinit var channel: MethodChannel
    private var context: Context? = null
    private var zaploxManager: ZaploxManager? = null
    var activity: Activity? = null

    override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
        context = flutterPluginBinding.applicationContext;
        channel = MethodChannel(flutterPluginBinding.binaryMessenger, "digitalkey")
        channel.setMethodCallHandler(this)
    }


    override fun onMethodCall(call: MethodCall, result: Result) {
        when (call.method) {
            "initZDK" -> initZDK(call, result)
            "fetchKey" -> fetchKey(call, result)
            "unLockDoor" -> unLockDoor(call, result)
            else -> result.notImplemented()
        }

    }

    override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
        channel.setMethodCallHandler(null)
    }

    private fun initZDK(call: MethodCall, result: Result) {
        val options: Map<String, String>? = call.arguments()
        if (zaploxManager == null) {
            runBlocking {
                options?.get("brand")?.let {
                    options["server"]?.let { it1 ->
                        ZaploxHelper().setupZDK(
                            appBrandName = it,
                            zaploxBackendUrl = it1,
                            requiredContext = context!!,
                            result = result
                        )
                    }
                }
            }
        }
    }

    private fun fetchKey(call: MethodCall, result: Result) {
        if (zaploxManager == null) {
            runBlocking {
                ZaploxHelper().fetchKeys(
                    result = result
                )
            }
        }
    }

    private fun unLockDoor(call: MethodCall, result: Result) {
        val options: Map<String, String>? = call.arguments()
        if (zaploxManager == null) {
            if (options != null) {
                runBlocking {
                    options["keyZid"]?.let { ZDK.zaploxManager.getKeyByZuid(options["keyZid"].toString())
                        ?.let { it1 -> ZaploxHelper().unlockDoor(key = it1, result = result) } }
                }
            }
        }
    }


    override fun onAttachedToActivity(binding: ActivityPluginBinding) {
        this.activity = binding.activity
    }

    override fun onDetachedFromActivityForConfigChanges() {
        this.activity = null
    }

    override fun onReattachedToActivityForConfigChanges(binding: ActivityPluginBinding) {
        activity = binding.activity
    }

    override fun onDetachedFromActivity() {
        this.activity = null
    }
}
