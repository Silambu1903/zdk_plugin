//
//  Account.h
//  Pods
//
//  Created by David Aberg on 12/08/15.
//
//

#import <Foundation/Foundation.h>
#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKAccount : ZDKObject

+ (id)shared;

typedef void (^ZDKAccountResponseBlock)(NSArray<ZDKAccount*> * __nullable sites, ZDKError * __nullable error, BOOL isCachedResponse);

@property(nonatomic) NSString* accountZuid;

- (void)createAccountWithPassword:(nullable NSString*)password completion:(nullable ZDKCompletionBlock)completeBlock;
- (void)loginWithIdentity:(nullable NSString *)identity password:(nullable NSString *)password completion:(nullable ZDKCompletionBlock)completeBlock;
- (void)updateDeviceToken:(NSString *)token completion:(nullable ZDKCompletionBlock)completeBlock;
- (void)updatePassword:(NSString *)oldPassword newPassword:(NSString *)newPassword completion:(nullable ZDKCompletionBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
