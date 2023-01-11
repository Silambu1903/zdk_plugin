import os.log
import ZDK

import Foundation


class ZaploxHelper{

    
    
     
    private static var sharedZDKHelper: ZaploxHelper = {
        return ZaploxHelper()
    }()

    class func shared() -> ZaploxHelper {
        return sharedZDKHelper
    }
    
    
    /// setUpZaploxMethod
    func setup(server: String, brand: String, completion:@escaping(Result<String, Error>) -> Void)  {
        ZDK().setup(withBrandName: brand, restURL: server){status,_,error in
            DispatchQueue.main.async {
                 if status == .setupSuccess || status == .alreadySetup {
                    completion(.success("ZDK Setup SuccessFully"))
                 }else{
                     if let e = error as? Error {
                           completion(.failure(e))
                         }
                 }
    
            }
        }
    }
    
  
   
    func fetchKeys(result: @escaping FlutterResult) {
        guard ZDK.isSetup() else {
            return
        }
        ZDK.zaploxManager().fetchKeys { keys, error in
            DispatchQueue.main.async {
                if (keys?.count ?? 0) > 0 {
                    result("Fetch Key Sucess")
                } else {
                    result("Fetch Key Failed")
                }
            }
        }
    }
 
    
   
    
    
    func unlockDoor(key: ZDKOKey,result: @escaping FlutterResult) {
        key.unlock { success, error in
            DispatchQueue.main.async {
                DispatchQueue.main.async {
                    if ((success?.isEmpty) != nil){
                        result("Door UnLocked SuccessFully")
                    }else{
                        result("Door UnLocked Failed")
                    }
                }
            }
        }
    }
    
    func unlock(with key: ZDKOKey,result: @escaping FlutterResult) {
        key.unlock { success, error in
            DispatchQueue.main.async {
                if ((success?.isEmpty) != nil){
                    result("Door UnLocked SuccessFully")
                }else{
                    result("Door UnLocked Failed")
                }
            }
        }
    }
 
}


enum ZDKError: Error {
    case FetchKeyFailed, apiFailed, corruptedData
}
