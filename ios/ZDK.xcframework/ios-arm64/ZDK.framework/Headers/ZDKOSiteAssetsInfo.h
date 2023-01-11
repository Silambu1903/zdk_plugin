//
//  ZDKOAssetsInfo.h
//  ZDK
//
//  Created by Diana Chabanova on 2020-03-26.
//  Copyright © 2020 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOResourceInfo.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kSiteAssetPreCheckedIn;
extern NSString *const kSiteAssetCheckedIn;
extern NSString *const kSiteAssetCheckOut;
extern NSString *const kSiteAssetCheckedOut;
extern NSString *const kSiteAssetPayment;
extern NSString *const kSiteAssetBreakfast;
extern NSString *const kSiteAssetFindReservation;
extern NSString *const kSiteAssetKeyTutorial;
extern NSString *const kSiteAssetError;
extern NSString *const kSiteAssetDiscover;
extern NSString *const kSiteAssetDemoRoom;
extern NSString *const kSiteAssetMobileKey;
extern NSString *const kSiteAssetTermsAndConditions;

/**
 @brief Representation of the Zaplox Site Assets Info object.
 */
@interface ZDKOSiteAssetsInfo: ZDKObject

/** @name Properties */

/**
 @brief Pre Checked In Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *preCheckedIn;

/**
 @brief Checked In Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *checkedIn;

/**
 @brief Check Out Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *checkOut;

/**
 @brief Checked Out Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *checkedOut;

/**
 @brief Payment Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *payment;

/**
 @brief Breakfast Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *breakfast;

/**
 @brief Find Reservation Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *findReservation;

/**
 @brief Key Tutorial Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *keyTutorial;

/**
 @brief Error Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *error;

/**
 @brief Discover Header Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *discover;

/**
 @brief Demo Room Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *demoRoom;

/**
 @brief Mobile Key Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *mobileKey;

/**
 @brief Terms and Conditions Image resources for site.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *termsAndConditions;

@end

NS_ASSUME_NONNULL_END
