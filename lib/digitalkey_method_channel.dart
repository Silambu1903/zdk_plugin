import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'digitalkey_platform_interface.dart';

/// An implementation of [DigitalkeyPlatform] that uses method channels.
class MethodChannelDigitalkey extends DigitalkeyPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('digitalkey');

  Future<String?> getPlatformVersion() async {
    final version =
        await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }

  @override
  Future<String?> initZDK({required String brand,required String server}) async {
    final zdk = await methodChannel
        .invokeMethod<String>('initZDK', <dynamic, dynamic>{
      'brand': brand,
      'server': server,
    });
    return zdk;
  }

  @override
  Future<String?> fetchKey() async {
    final fetchKey = await methodChannel.invokeMethod<String>('fetchKey');
    return fetchKey;
  }

  @override
  Future<String?> unLockDoor({required String keyZid}) async {
    final unLockDoor = await methodChannel
        .invokeMethod<String>('unLockDoor', <dynamic, dynamic>{
      'keyZid': keyZid,
    });
    return unLockDoor;
  }
}
