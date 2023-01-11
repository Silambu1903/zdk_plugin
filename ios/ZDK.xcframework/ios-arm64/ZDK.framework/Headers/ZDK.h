//
//  ZDK.h
//  ZDK
//
//  Created by David Aberg on 16/09/16.
//  Copyright © 2016 Zaplox AB. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ZDK/ZDKOReservation.h>
#import <ZDK/ZDKOReservationWithOffers.h>
#import <ZDK/ZDKOKey.h>
#import <ZDK/ZDKONotification.h>
#import <ZDK/ZDKOOffer.h>
#import <ZDK/ZDKOOffers.h>
#import <ZDK/ZDKOSite.h>
#import <ZDK/ZDKOTicket.h>
#import <ZDK/ZDKORoom.h>
#import <ZDK/ZDKOCustomLog.h>
#import <ZDK/ZDKConnectivityManager.h>
#import <ZDK/ZDKOIdentity.h>
#import <ZDK/ZaploxManager.h>
#import <ZDK/ZDKConstantsAndEnums.h>
#import <ZDK/ZDKWebControlls.h>
#import <ZDK/ZDKError.h>
#import <ZDK/ZDKAccount.h>
#import <ZDK/ZDKOIdentity.h>
#import <ZDK/ZDKOFolio.h>
#import <ZDK/ZDKOFolioItem.h>
#import <ZDK/ZDKODepositInfo.h>
#import <ZDK/ZDKOFolioWindow.h>
#import <ZDK/ZDKOPaymentWindow.h>
#import <ZDK/ZDKOPayment.h>
#import <ZDK/ZDKOTaxItem.h>
#import <ZDK/ZDKLog.h>
#import <ZDK/ZDKORoomInfo.h>
#import <ZDK/ZDKOAmenity.h>
#import <ZDK/ZDKOResourceInfo.h>
#import <ZDK/ZDKVerificationView.h>
#import <ZDK/ZDKOSiteAssetsInfo.h>
#import <ZDK/ZDKOPaymentInfo.h>
#import <ZDK/ZDKOCustomer.h>

//! Project version number for ZDK.
FOUNDATION_EXPORT double ZDKVersionNumber;

//! Project version string for ZDK.
FOUNDATION_EXPORT const unsigned char ZDKVersionString[];

/**
 This object is the entry point for using the Zaplox Development Kit.
 */
@protocol ZDK

/** @name Type methods */

/**
 @brief This method is used to get the singleton ZaploxManager. The ZDK must be successfully setup before calling this method.

 @return A Singleton object
 */
+ (nonnull id<ZaploxManagerProtocol>)zaploxManager;

/**
 @brief Checks if ZDK has been setup on this device.

 @return YES or NO
 */
+ (BOOL)isSetup;

/** @name Methods */

/**
 @brief Sets up the use of the Zaplox development kit.
 Creates anonymous account and logs it in. Credentials and device info are saved locally after
 succesful log in. Note that ZDK setup needs to finish successfully before any other functions
 in the SDK can be used
 
 @param brandName        App specific brand
 @param completeBlock    ZDKSetupResponseBlock ZDKSetupStatus
 */
- (void)setupWithBrandName:(nonnull NSString *)brandName completion:(nonnull ZDKSetupResponseBlock)completeBlock;

/**
 @brief Sets up the use of the Zaplox development kit against a specified server.
 Creates anonymous account and logs it in. Credentials and device info are saved locally after
 succesful log in. Note that ZDK setup needs to finish successfully before any other functions
 in the SDK can be used
 
 @param brandName      App specific brand
 @param restURL          The url to be used for backend REST calls
 @param completeBlock    ZDKSetupResponseBlock ZDKSetupStatus
 */
- (void)setupWithBrandName:(nonnull NSString *)brandName restURL:(nonnull NSString *)restURL completion:(nonnull ZDKSetupResponseBlock)completeBlock;

/*
 @brief Updates the push token on Zaplox servers for current users device.

 @param deviceToken      The unique device token retrived from Firebase when registering for push.
 @param completeBlock    ZDKCompletionBlock
 */
- (void)updateDeviceTokenForPush:(nullable NSString *)deviceToken completion:(nonnull ZDKCompletionBlock)completeBlock;

@end

/**
 This class is the entrypoint for using the Zaplox Development Kit.
*/

@interface ZDK : NSObject <ZDK>

- (void)setupWithBrandName:(nonnull NSString *)brandName restURL:(nonnull NSString *)restURL wcURL:(nullable NSString *)wcURL completion:(nonnull ZDKSetupResponseBlock)completeBlock;

- (void)loginWithBrandName:(nonnull NSString *)brandName restURL:(nonnull NSString *)restURL wcURL:(nullable NSString *)wcURL identity:(nonnull NSString *)identity password:(nonnull NSString *)password completion:(nonnull ZDKLoginResponseBlock)completeBlock;

+ (nullable NSString *)authToken;

+ (nullable NSString *)accountZuid;

@end
