import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'digitalkey_method_channel.dart';

abstract class DigitalkeyPlatform extends PlatformInterface {
  /// Constructs a DigitalkeyPlatform.
  DigitalkeyPlatform() : super(token: _token);

  static final Object _token = Object();

  static DigitalkeyPlatform _instance = MethodChannelDigitalkey();

  /// The default instance of [DigitalkeyPlatform] to use.
  ///
  /// Defaults to [MethodChannelDigitalkey].
  static DigitalkeyPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [DigitalkeyPlatform] when
  /// they register themselves.
  static set instance(DigitalkeyPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }



  Future<String?> initZDK({required String brand,required String server}) {
    throw UnimplementedError('ZDK init Failed');
  }

  Future<dynamic> fetchKey() {
    throw UnimplementedError('Fetch Key Failed');
  }

  Future<String?> unLockDoor({required String keyZid}) {
    throw UnimplementedError('UnLock Door Failed');
  }
}
