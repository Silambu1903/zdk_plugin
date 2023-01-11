//
//  ZDKConnectivityManager.h
//  Pods
//
//  Created by David Aberg on 29/10/15.
//
//

#import <Foundation/Foundation.h>

@interface ZDKConnectivityManager : NSObject

+ (id)shared;

@property (nonatomic) BOOL isInternetAvailable;
@property (nonatomic) BOOL isBluetoothEnabled;

@end
