//
//  ZDKError.h
//  ZDK
//
//  Created by David Aberg on 04/11/16.
//  Copyright © 2016 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKConstantsAndEnums.h"


/**
 ZDK Error object protocol
 */
@protocol ZDKError

/** @name Properties */

/**
 @brief ZDK Error code

 @return ZDKErrorCode
 */
- (ZDKErrorCode)code;

/**
 @brief ZDK Error message
 */
- (NSString *)message;

@end

@interface ZDKError : NSObject<ZDKError>

@property (nonatomic) NSString *stringCode;

+ (instancetype)errorWithCode:(ZDKErrorCode)code message:(NSString *)message;
+ (instancetype)errorWithStringCode:(NSString *)code message:(NSString *)message;
+ (NSDictionary *)codeByStringDict;

@end
