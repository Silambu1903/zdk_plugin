//
//  ZDKOCustomLog.h
//  Pods
//
//  Created by David Aberg on 09/06/16.
//
//

#import <Foundation/Foundation.h>

@interface ZDKOCustomLog : NSObject

+ (void)postCustomLogWithTag:(NSString *)tag message:(NSString *)message keyZuid:(NSString *)keyZuid reservationZuid:(NSString *)reservationZuid custom:(NSDictionary *)custom;

@end
