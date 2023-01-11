//
//  NetworkHelper.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import <Foundation/Foundation.h>
#import "ZDKTransaction.h"
#import "ZDKConnectivityManager.h"
#import "ZDKConstantsAndEnums.h"
#import "ZDKError.h"

@interface ZDKNetworkHelper : NSObject

+ (NSString *)restURL;
+ (NSString *)wcURL;

+ (ZDKError *)noInternetError;

+ (void)get:(NSString *)path transaction:(ZDKTransaction *)transaction params:(NSDictionary *)params cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKCompletionBlock)completeBlock;

+ (void)post:(NSString *)path transaction:(ZDKTransaction *)transaction params:(NSDictionary *)params completion:(ZDKCompletionBlock)completeBlock;

+ (void)put:(NSString *)path transaction:(ZDKTransaction *)transaction params:(NSDictionary *)params completion:(ZDKCompletionBlock)completeBlock;

+ (NSString *)dictToJsonString:(NSDictionary *)dict;

+ (NSURLSessionDataTask *)dataTaskWithPath:(NSString *)path method:(NSString *)method transaction:(ZDKTransaction *)transaction params:(NSDictionary *)params completion:(ZDKCompletionBlock)completeBlock;

#if DEBUG

+ (void)debugFailRequests:(NSDictionary *)requests;

+ (NSNumber *)failIfNeeded:(NSString *)method path:(NSString *)path;

#endif
@end
