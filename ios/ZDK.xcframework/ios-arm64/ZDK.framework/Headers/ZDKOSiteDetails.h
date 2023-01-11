//
//  ZDKOSiteDetails.h
//  Pods
//
//  Created by David Aberg on 25/09/15.
//
//

#import "ZDKObject.h"
#import "ZDKOAddressInfo.h"
#import "ZDKOResourceInfo.h"
#import "ZDKOCommonInfo.h"
#import "ZDKOContactInfo.h"
#import "ZDKOSiteAssetsInfo.h"
#import "ZDKOPaymentInfo.h"
#import "ZDKOAliceDetails.h"
#import "ZDKLockVendor.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Site details object.
 */
@protocol ZDKSiteDetails

/** @name Properties */

/**
 @brief Contact info for site.

 @return ZDKContactInfo
 */
@optional
@property (nullable, nonatomic, readonly) ZDKOContactInfo *contactInfo;

/**
 @brief Address info for site.

 @return ZDKAddressInfo
 */
@property (nullable, nonatomic, readonly) ZDKOAddressInfo *addressInfo;

/**
 @brief Payment info for site.

 @return ZDKPaymentInfo
 */
@optional
@property (nullable, nonatomic, readonly) ZDKOPaymentInfo *paymentInfo;


/**
 @brief Header image resources for site.

 @return ZDKResourceInfoProtocol
 */
@property (nullable, nonatomic, readonly) ZDKOResourceInfo *appResourceInfo;

/**
 @brief Key image resources for site.

 @return ZDKResourceInfoProtocol
 */
@property (nullable, nonatomic, readonly) ZDKOResourceInfo *doorResourceInfo;

/**
 @brief Premium app image resources for site.
 */
@property (nullable, nonatomic, readonly) ZDKOSiteAssetsInfo *assetsResourceInfo;

/**
 @brief A string representation of the site timezone.
 */
@property (nullable, nonatomic, readonly) NSString *timezone;

/**
 @brief The site's booking uri.
 */
@property (nullable, nonatomic, readonly) NSString *bookingUri;

/**
 @brief The site's FAQ uri.
 */
@property (nullable, nonatomic, readonly) NSString *faqUri;

/**
 @brief The site's data policy uri.
 */
@property (nullable, nonatomic, readonly) NSString *dataPolicyUri;

/**
 @brief The site's terms and conditions uri.
 */
@property (nullable, nonatomic, readonly) NSString *termsAndConditionsUri;

/**
 * @brief The vendor supplying the key.
 *
 * @return ZDKLockVendor
 */
- (ZDKLockVendor)lockVendor;

/**
 @brief Alice chat details for site.
 */
@property (nullable, nonatomic, readonly) ZDKOAliceDetails *aliceDetails;

@end

/**
 Representation of the Zaplox Site details object.
 */
@interface ZDKOSiteDetails : ZDKObject<ZDKSiteDetails>

@property (nullable, nonatomic, readonly) ZDKOCommonInfo *commonInfo;
@property (nonatomic, readonly) BOOL validationEnabled;
@property (nullable, nonatomic, readonly) NSString *shareLimit;
@property (nonatomic, readonly) BOOL dormakabaAmbiance;

@end

NS_ASSUME_NONNULL_END
