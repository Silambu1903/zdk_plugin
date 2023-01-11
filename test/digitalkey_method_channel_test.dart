import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:digitalkey/digitalkey_method_channel.dart';

void main() {
  MethodChannelDigitalkey platform = MethodChannelDigitalkey();
  const MethodChannel channel = MethodChannel('digitalkey');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
