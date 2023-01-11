import Flutter
import ZDK


public class SwiftDigitalkeyPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "digitalkey", binaryMessenger: registrar.messenger())
    let instance = SwiftDigitalkeyPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)

 
  }

    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult)  {
      switch call.method  {
          case "initZDK":
           self.initZDK(call: call, result: result)
          break
          case "fetchKey":
           self.fetchKeys(call: call, flutterResult:result)
          break
          case "unLockDoor":
           self.unLockDoor(call: call, result: result)
            default:
                result(FlutterMethodNotImplemented)
            }

  }
  
    
    public func initZDK(call: FlutterMethodCall, result: @escaping FlutterResult)    {
        let arguments = call.arguments as! Dictionary<String, String>
        do{
            let server = (arguments["server"] ?? "") as String
            let brand = (arguments["brand"] ??  "") as String
            ZaploxHelper.shared().setup(server: server, brand: brand){ result in
                switch result {
                    case let .failure(error):
                        print("error:", error)
                case .success(_):
                    print("succes:")
                }
            }
        }
    }
            
          
    
    public func fetchKeys(call: FlutterMethodCall, flutterResult: @escaping FlutterResult)    {
        ZaploxHelper.shared().fetchKeys(result: flutterResult)
    }
    
    
    private func unLockDoor(call: FlutterMethodCall, result: @escaping FlutterResult){
        var key: ZDKOKey! = nil
        let arguments = call.arguments as! Dictionary<String, String>
        do {
            key = ZDK.zaploxManager().key(byZuid: arguments["keyZid"])
            if key != nil {
                ZaploxHelper.shared().unlock(with: key,result: result)
            }
        }
    }
}
