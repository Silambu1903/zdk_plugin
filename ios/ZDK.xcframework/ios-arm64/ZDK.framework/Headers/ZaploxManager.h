//
//  ZaploxManager.h
//  ZDK
//
//  Created by David Aberg on 10/10/16.
//  Copyright © 2016 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKOReservationWithOffers.h"
#import "ZDKOReservation.h"
#import "ZDKOKey.h"
#import "ZDKFindParameters.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The ZaploxManager is responsible for getting Keys and Reservations related to the device account.
 */
@protocol ZaploxManagerProtocol

/** @name Type methods */

/**
 @brief  The singleton ZaploxManager.

 @note ZDK must be successfully setup before calling this method.

 @return A singleton object.
*/
+ (id<ZaploxManagerProtocol>)shared;

/** @name Properties */

/**
 @brief Device identifier.

 @note Retrieves a unique identifier of the device, which can be used in the Zaplox Ecosystem to create keys for this device.

 @return String representation of the unique identifier of the device.
 */
- (nullable NSString *)deviceZuid;

/**
 @brief Keys for this device.

 @note Retrieves all keys that are stored locally on the device. Before using this method, keys must be fetched with fetchKeysWithCompletion:
 @see fetchKeysWithCompletion:

 @return The list of keys currently present on the device.
 */
- (NSArray<ZDKOKey*> *)keys;

/** @name Sites */

/**
 @brief Get available sites.

 @note Performs a get request to the Zaplox backend to retrive all sites associated with the specific brand name.

 @param completeBlock ZDKOSitesResponseBlock
 @param cachePolicy   ZDKCachePolicy
 */
- (void)getSitesWithCachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOSitesResponseBlock)completeBlock;

/**
 @brief Get available sites with content urls for branding assets.

 @note Performs a get request to the Zaplox backend to retrive all sites associated with the specific brand name including content urls for branding assets.

 @param completeBlock ZDKOSitesResponseBlock
 */
- (void)getSitesWithImageInfo:(ZDKOSitesResponseBlock)completeBlock;

/** @name Reservations */

/**
 @brief Get all reservations associated with the device.

 @note Performs a get request to the Zaplox backend to retrive all reservations found for the device. You have to call findReservationWithParameters:completion:, findReservationWithParameters:includeRoomInfo:completion: or findSharedReservationWithReference:phone:completion: methods at least once to find the reservation in the PMS so it can be registered in Zaplox backend and saved in cache.
 @see findReservationWithParameters:completion:
 @see findReservationWithParameters:includeRoomInfo:completion:
 @see findSharedReservationWithReference:phone:completion:

 @param completeBlock ZDKOReservationsResponseBlock
 @param cachePolicy   ZDKCachePolicy
 */
- (void)getReservationsWithCachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOReservationsResponseBlock)completeBlock;

/**
 @brief Fetch reservation by zuid.

 @note Performs a get request to the Zaplox backend to retrive a reservation object. You have to call findReservationWithParameters:completion:, findReservationWithParameters:includeRoomInfo:completion: or findSharedReservationWithReference:phone:completion: methods at least once to find the reservation in the PMS so it can be registered in Zaplox backend and saved in cache.
 @see findReservationWithParameters:completion:
 @see findReservationWithParameters:includeRoomInfo:completion:
 @see findSharedReservationWithReference:phone:completion:

 @param zuid          The Zaplox unique identifier for a reservation object.
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOReservationResponseBlock
 */
- (void)fetchReservationById:(NSString *)zuid cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOReservationResponseBlock)completeBlock;

/**
 @brief Fetch updated reservation by zuid from PMS.

 @note Performs a fetch request to retrive a reservation object from the PMS. Use this method when you want to fetch latest reservation changes from the PMS.

 @param zuid          The Zaplox unique identifier for a reservation object.
 @param completeBlock ZDKOReservationResponseBlock
 */
- (void)fetchUpdatedReservationById:(NSString *)zuid completion:(ZDKOReservationResponseBlock)completeBlock;

/**
 @brief Find shared reservation by zuid and token.

 @note Performs a get request to the Zaplox backend to retrive a reservation object. A cloned key will be created and activated for the new device.

 @param zuid          The Zaplox unique identifier for a reservation object.
 @param token         The share token provided.
 @param completeBlock ZDKOReservationResponseBlock
 */
- (void)findSharedReservationById:(NSString *)zuid withToken:(NSString *)token completion:(ZDKOReservationResponseBlock)completeBlock;

/**
 @brief Find reservation.

 @note Asynchronously try to find reservations with given parameters in the PMS. This method should be used when a PMS Reference exists.
 When called, ZDK will send a find reservation request to Zaplox backend.
 Backend will use siteID to look up communication path to the PMS of the hotel. Backend will then send a find reservation request to the PMS at
 the matching hotel. Find results are asynchronously reported to Zaplox backend.
 ZDK periodically polls backend for status of the find request and when finished matching reservations are returned asynchronously to caller.

 @param parameters  Search parameters. Depending on site, some parameters may be mandatory.
 @param completeBlock ZDKOReservationsResponseBlock
  */
- (void)findReservationWithParameters:(ZDKFindParameters *)parameters completion:(ZDKOReservationsResponseBlock)completeBlock;

/**
 @brief Find reservation and include extra romm info.

 @note Asynchronously try to find reservations with given parameters in the PMS. This method should be used when a PMS Reference exists.
 When called, ZDK will send a find reservation request to Zaplox backend.
 Backend will use siteID to look up communication path to the PMS of the hotel. Backend will then send a find reservation request to the PMS at
 the matching hotel. Find results are asynchronously reported to Zaplox backend.
 ZDK periodically polls backend for status of the find request and when finished matching reservations are returned asynchronously to caller.

 @param parameters  Search parameters. Depending on site, some parameters may be mandatory.
 @param roomInfo Boolean to enable extra room info fetching.
 @param completeBlock ZDKOReservationsResponseBlock
 */
- (void)findReservationWithParameters:(ZDKFindParameters *)parameters includeRoomInfo:(BOOL)roomInfo completion:(ZDKOReservationsResponseBlock)completeBlock;

/** @name Keys */

/**
 @brief Fetch all keys available for the device.

 @note Asynchronously try to fetch all keys available to the current device.<p>
 When called, ZDK will match internal key representations to internal
 third-party mobile key libraries and initiate and setup these internal libraies as necessary.<p>
 The initial setup of some of the internal third-party mobile key libraries may take some time.

 Reponse includes all keys found. The array may contain invalid and inactive keys. Please, use the property keyState (ZDKKeyState) to check the state if you're using keys from the response. Otherwise, use method keys() on ZaploxManager or ZDKOReservation.
 
 @param completeBlock ZDKOKeysResponseBlock
 */
- (void)fetchKeysWithCompletion:(ZDKOFetchKeysResponseBlock)completeBlock;

/**
 @brief Fetch key for the door.

 @note Retrieves the key for a specific room, that is stored locally on the device. Before using this method, keys must be fetched with fetchKeysWithCompletion:
 @see fetchKeysWithCompletion:

 @param roomReference The identifier for the Room.

 @return The key for the given room, nil if not present.
 */
- (nullable ZDKOKey*)keyByDoorReference:(nullable NSString *)roomReference;

/**
 @brief Fetch door.

 @note Retrieves the door for a specific room.

 @param doorZuid The identifier for the door.

 @return The door.
 */
- (void)doorByZuid:(nullable NSString *)doorZuid completion:(ZDKODoorResponseBlock)completeBlock;

/**
 @brief Fetch key by zuid.

 @note Retrieves the key with a specific identifier, that is stored locally on the device. Before using this method, Keys must be fetched with fetchKeysWithCompletion:
 @see fetchKeysWithCompletion:

 @param keyZuid The unique Zaplox Identifier for the key.

 @return The key with the given identifier, nil if not present.
 */
- (nullable ZDKOKey*)keyByZuid:(nullable NSString*)keyZuid;

/*
@brief Performs a post request to the backend to retrive an indentity zuid and send a sms with verification code.

@param phoneNumber   The phone number to bind identity to.
@param completeBlock ZDKCompletionBlock
*/
- (void)requestSMSChallenge:(NSString *)phoneNumber completion:(ZDKCompletionBlock)completeBlock;

/*
@brief Performs a post request to the backend to verify the indentity with verification code.

@param identityZuid     The identioty zuid received from requestSMSChallenge call.
@param code             The code received via sms.
@param completeBlock    ZDKCompletionBlock
*/
- (void)verifyPhone:(NSString *)identityZuid withCode:(NSString *)code completion:(ZDKCompletionBlock)completeBlock;

/*
 @brief Performs a get request to the backend to retrive configuration for the find reservation flow.

 @param siteZuid      zuid of the site you want to fetch configuration for
 @param countryCode   Selected country code for find reservation
 @param completeBlock ZDKCompletionBlock
 */
- (void)fetchReservationFindConfigurationForSite:(NSString *)siteZuid countryCode:(NSString *)countryCode completion:(ZDKCompletionBlock)completion;

/*
 @brief Performs a get request to the backend to retrive configuration for the guest registration flow.

 @param siteZuid      zuid of the site you want to fetch guest registration for
 @param countryCode   Selected country code for guest registration
 @param completeBlock ZDKCompletionBlock
 */
- (void)fetchGuestRegistrationConfigurationForSite:(NSString *)siteZuid countryCode:(NSString *)countryCode completion:(ZDKCompletionBlock)completion;


/**
 @brief Disable all logging from ZDK.
 */
- (void)disableLogging;

#if DEBUG
- (void)debugFailRequests:(NSDictionary *)requests;
#endif

@end


/**
 @brief The ZaploxManager is responsible for getting Keys and Reservations related to the device account.
 */
@interface ZaploxManager : NSObject <ZaploxManagerProtocol>

/*
 @brief Performs a get request to the backend to retrive a reservationWithOffers object.
 
 @param reservationId The id of the reservation to get.
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOReservationWithOffersResponseBlock
 */
- (void)getReservationWithOffersById:(NSString *)reservationId cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOReservationWithOffersResponseBlock)completeBlock;


/*
 @brief Performs a get request to the backend to retrive an array of reservationWithOffers objects.
 
 @param reference     The reference of the reservation.
 @param nameFrag      The surname of the person who booked the reservation.
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOReservationsWithOffersResponseBlock
 */
- (void)findReservationsWithOffersByReference:(nullable NSString *)reference nameFragment:(nullable NSString *)nameFrag cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOReservationsWithOffersResponseBlock)completeBlock;

/*
 @brief Performs a get request to the backend to retrive an array of shared reservationWithOffers objects.

 @param pin           The pin of the reservation.
 @param phone         The phone of the person who booked the reservation.
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOReservationsWithOffersResponseBlock
 */
- (void)findSharedReservationsWithOffersByReference:(nullable NSString *)pin phone:(nullable NSString *)phone cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOReservationsWithOffersResponseBlock)completeBlock;

- (void)log:(NSString *)message;
- (void)logInfo:(NSString *)message;
- (void)logError:(NSString *)message;
- (void)logDebug:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
