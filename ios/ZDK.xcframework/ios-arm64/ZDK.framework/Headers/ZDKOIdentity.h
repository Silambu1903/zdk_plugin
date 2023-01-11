//
//  Identity.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKOIdentity : ZDKObject

+ (void)findByValue:(NSString *)value completion:(ZDKCompletionBlock)completeBlock;
+ (void)bindIdentity:(NSString *)identity completion:(ZDKCompletionBlock)completeBlock;
+ (void)verifyIdentity:(NSString *)identityId withPin:(NSString *)pin completion:(ZDKCompletionBlock)completeBlock;
+ (void)getAllWithCachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKCompletionBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
