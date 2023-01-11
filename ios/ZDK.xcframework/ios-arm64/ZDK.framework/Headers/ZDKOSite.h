//
//  Site.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import "ZDKObject.h"
#import "ZDKOSiteDetails.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Site in the Zaplox system.
 */
@protocol ZDKSite

/** @name Properties */

/**
 @brief The unique identifier of the site.
 */
@optional
@property (nonatomic, readonly) NSString *siteZuid;

/**
 @brief The unique identifier of the customer.
 */
@optional
@property (nonatomic, readonly) NSString *customerZuid;

/**
 @brief The name of the site.
 */
@property (nonatomic, readonly) NSString *name;

/**
 @brief The description of the site.
 */
@property (nonatomic, readonly) NSString *siteDescription;

/**
 @brief Site meta data such as timezone.

 @return ZDKSiteDetails
 */
@property (nonatomic, readonly) ZDKOSiteDetails *siteDetails;

@end

/**
 @brief Representation of a Site in the Zaplox system.
 */
@interface ZDKOSite : ZDKObject <ZDKSite>

+ (NSArray<ZDKOSite *> *)getAllCached;
+ (ZDKOSite *)getCachedByZuid:(NSString *)zuid;
+ (void)getByZuid:(NSString *)zuid cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOSiteResponseBlock)completeBlock;
+ (void)getAllWithCachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOSitesResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
