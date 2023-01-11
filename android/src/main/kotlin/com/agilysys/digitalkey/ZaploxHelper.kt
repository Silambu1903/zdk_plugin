package com.agilysys.digitalkey


import android.content.Context
import android.util.Log
import android.view.View
import com.zaplox.sdk.keystore.UnlockData
import com.zaplox.zdk.*
import io.flutter.plugin.common.MethodChannel
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.runBlocking
import kotlinx.coroutines.withContext

class ZaploxHelper {

    suspend fun setupZDK(
        appBrandName: String,
        zaploxBackendUrl: String,
        requiredContext: Context,
        result: MethodChannel.Result
    ) {
        withContext(Dispatchers.IO) {
            if (!ZDK.isSetup) {
                ZDK.setup(
                    requiredContext, appBrandName, zaploxBackendUrl,
                    object : ZDK.OnSetupListener {
                        override fun onSetupComplete(zaploxManager: ZaploxManager) {
                            result.success(zaploxManager.deviceZuid)
                        }
                        override fun onSetupFailed(errorType: ErrorType?) {
                            result.success(EnumMessage.ZDKSetupFailed.toString())
                        }
                    },
                )
            } else {
                result.success(EnumMessage.ZDKSetupSuccessFully.toString())
            }

        }
    }


     fun unlockDoor(key: Key, result: MethodChannel.Result) {
        key.unlock(object : Key.OnUnlockListener {
            override fun onUnlock(data: UnlockData) {
                result.success(EnumMessage.DoorUnlockedSuccessfully.toString())
            }

            override fun onUnlockFailed(errorType: ErrorType, data: UnlockData) {
                result.success(EnumMessage.FailedToUnlockDoor.toString())
            }
        })
    }

     fun stopUnlock(key: Key?, result: MethodChannel.Result) {
        key?.stopUnlock()
        result.success("")
    }

    suspend fun fetchKeys(result: MethodChannel.Result) {
        withContext(Dispatchers.IO) {
            if (ZDK.isSetup) {
                ZDK.zaploxManager.fetchKeys(object : ZaploxManager.OnFetchKeysListener {
                    override fun onFetchKeysFinished(keys: List<Key>) {
                        if (keys.isNotEmpty()) {
                            result.success(EnumMessage.FetchKeySuccess.toString())
                        } else {
                            result.success(EnumMessage.FetchKeyEmpty.toString())
                        }

                    }

                    override fun onFetchKeysFailed(errorType: ErrorType, keys: List<Key>) {
                        if (ZDKErrorType.SERVICE_BUSY == errorType) {
                            result.success(EnumMessage.ServiceBusy.toString())
                        } else if (ZDKErrorType.KEYSTORE_SYNC_ERROR == errorType) {
                            result.success(EnumMessage.KeyStoreSyncError.toString())
                        } else {
                            result.success(EnumMessage.FetchKeyFailed.toString())
                        }
                    }
                })
            } else {
                result.success(EnumMessage.ZDKSetupFailed.toString())
            }

        }
    }
}