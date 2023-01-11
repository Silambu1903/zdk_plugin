
import 'digitalkey_platform_interface.dart';

class Digitalkey {

  Future<String?> initZDK({required String brand,required String server}) {
    return DigitalkeyPlatform.instance.initZDK(brand: brand,server: server);
  }

  Future<dynamic> fetchKey() {
    return DigitalkeyPlatform.instance.fetchKey();
  }

  Future<String?> unLockDoor({required dynamic keyZid}) {
    return DigitalkeyPlatform.instance.unLockDoor(keyZid: keyZid);
  }
}
