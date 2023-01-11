import 'package:flutter_test/flutter_test.dart';
import 'package:digitalkey/digitalkey.dart';
import 'package:digitalkey/digitalkey_platform_interface.dart';
import 'package:digitalkey/digitalkey_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockDigitalkeyPlatform
    with MockPlatformInterfaceMixin
    implements DigitalkeyPlatform {


  @override
  Future<String?> initZDK({required String brand,required String server}) {
    // TODO: implement initZDK
    throw UnimplementedError();
  }

  @override
  Future fetchKey() {
    // TODO: implement fetchKey
    throw UnimplementedError();
  }

  @override
  Future<String?> unLockDoor({required String keyZid}) {
    // TODO: implement unLockDoor
    throw UnimplementedError();
  }

  
}

void main() {
  final DigitalkeyPlatform initialPlatform = DigitalkeyPlatform.instance;

  test('$MethodChannelDigitalkey is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelDigitalkey>());
  });

  test('getPlatformVersion', () async {
    Digitalkey digitalkeyPlugin = Digitalkey();
    MockDigitalkeyPlatform fakePlatform = MockDigitalkeyPlatform();
    DigitalkeyPlatform.instance = fakePlatform;


  });
}
