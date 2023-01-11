//
//  Offer.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import "ZDKObject.h"
#import "ZDKOOfferFeature.h"
#import "ZDKOResourceInfo.h"
#import "ZDKOPrice.h"
#import "ZDKNetworkHelper.h"

@class ZDKOOffer, ZDKOOffers;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Block definition
 *
 @param offers           NSArray<ZDKOOffer> ZDKOOffer
 @param error            NSError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKOOffersResponseBlock)(NSArray<ZDKOOffer*> * __nullable offers, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 *
 @param offers           ZDKOOffers A container for lists of special and site offers for reservation
 @param error            NSError
 */
typedef void (^ZDKOAllOffersResponseBlock)(ZDKOOffers * __nullable offers, ZDKError * __nullable error);


@protocol ZDKOffer

/** @name Properties */

@property (nullable, nonatomic, readonly) NSString *caption;
@property (nullable, nonatomic, readonly) NSString *desc;
@property (nullable, nonatomic, readonly) NSString *title;
@property (nullable, nonatomic, readonly) NSArray *offerFeatures;

@property (nullable, nonatomic, readonly) ZDKOResourceInfo *resourceInfo;
@property (nullable, nonatomic, readonly) NSString *subType;
@property (nullable, nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) BOOL isDirectToLink;
@property (nonatomic, readonly) BOOL hasNestedOffers;
@property (nullable, nonatomic, readonly) ZDKOPrice *price;
@property (nullable, nonatomic, readonly) NSString *processTitle;
@property (nullable, nonatomic, readonly) NSString *processUriOverride;

@property (nullable, nonatomic, readonly) NSString *zuid;
@property (nullable, nonatomic, readonly) NSString *siteZuid;

/** @name Public methods */

/**
@brief Performs a get request to the backend to retrive an array of general customer offers.

@param completeBlock ZDKOOffersResponseBlock
*/
+ (void)getCustomerOffersWithCompletion:(ZDKOOffersResponseBlock)completeBlock;

/**
 @brief Performs a get request to the backend to retrive an array of general site offers.

 @param siteId        Zaplox Id for the site to get offers from.
 @param completeBlock ZDKOOffersResponseBlock
 */
+ (void)getOffersBySiteId:(NSString *)siteId completion:(ZDKOOffersResponseBlock)completeBlock;

/**
 @brief Performs a get request to the backend to retrieve an array of special offers available for a reservation.

 @param reservationId NSString
 @param completeBlock ZDKOOffersResponseBlock
 */
+ (void)getOffersByReservationId:(NSString *)reservationId completion:(ZDKOOffersResponseBlock)completeBlock;

/**
 @brief Performs a get request to the backend to retrieve an array of special, site and customer offers available for a reservation.

 @param reservationId NSString
 @param completeBlock ZDKOOffersResponseBlock
 */
+ (void)getAllOffersByReservationId:(NSString *)reservationId completion:(ZDKOAllOffersResponseBlock)completeBlock;

@end

/**
 @brief Representation of the Zaplox object Offer.
 */
@interface ZDKOOffer : ZDKObject<ZDKOffer>

/**
 @brief Performs a get request to the backend to retrive an array of special and upgrade offers.

 @param reservationId Optional - Call with nil to limit results to offers with type GENERAL
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOOffersResponseBlock
 */
+ (void)getOffersByReservationId:(nullable NSString *)reservationId cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOOffersResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
