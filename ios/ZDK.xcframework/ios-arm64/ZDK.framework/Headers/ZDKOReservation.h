//
//  Reservation.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import <Foundation/Foundation.h>
#import "ZDKObject.h"
#import "ZaploxManager.h"
#import "ZDKOOffer.h"
#import "ZDKOGuest.h"
#import "ZDKOObjectLink.h"
#import "ZDKOFolio.h"
#import "ZDKOKey.h"
#import "ZDKOSite.h"
#import "ZDKOPaymentWindow.h"
#import "ZDKORoomInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Reservation in the Zaplox system.
 */
@protocol ZDKReservation

#pragma mark Properties

/** @name Properties */

/**
@brief Will get a locally stored key that matches the reservation.

@note Call the method fetchKeysWithCompletion: on ZaploxManager before to make sure the key exists and have the correct state.
*/
- (nullable ZDKOKey *)key;

/**
 @brief Will get a locally stored site that matches the reservation.
*/
- (ZDKOSite *)site;

/**
 @brief Check-in date.
 */
- (NSDate *)checkinAt;

/**
 @brief Checkout date.
 */
- (NSDate *)checkoutAt;

/**
 @brief Date when the reservation was first imported from the PMS.
 */
- (NSDate *)createdAt;

/**
 @brief Date when the reservation was created in the PMS.
 */
- (nullable NSDate *)pmsCreatedAt;

/**
 @brief The ZDKOFolio connected to this reservation.
 */
- (nullable ZDKOFolio *)folio;

/**
 @brief The ZDKODepositInfo connected to this reservation.
 */
- (nullable ZDKODepositInfo *)depositInfo;

/**
 @brief The properties associated with this reservation.
 */
- (nullable NSDictionary *)properties;

/**
 @brief Estimated time of guest arrival as reported by guest.
 */
- (nullable NSDate *)estimatedArrivalAt;

/**
 @brief Guest details and contact information for the primary guest.
 */
- (nullable ZDKOGuest *)guest;

/**
 @brief Generic note as imported from PMS.

 @note Example: "Please reserve parking space for late arrival."
 */
- (nullable NSString *)note;

/**
 @brief List of external and internal references for reservation.

 @note Example: {"confirmation_id": "42350138","reservation_number": "1d26545b126203" }
 */
- (NSDictionary *)references;

/**
 @brief Get the PMSReference.

 */
- (NSString *)PMSReference;

/**
 @brief State of reservation.

 @return ZDKOReservationState
*/
- (ZDKOReservationState)reservationState;

/**
 @brief String representation of reservationState.
 */
- (NSString *)state;

/**
 @brief The Date when Reservation was last updated with data from PMS.

 @note Updates may occur as a result of various Reservation operations such as
 check in and check out.
 
 @return The Date the Reservation was last updated with PMS data.
 */
- (NSDate *)updatedAt;

/**
 @brief The unique identifier of this reservation.
 
  */
- (NSString *)zuid;

/**
 @brief The room info as configured in the Zaplox portal.

 @return ZDKRoomInfo
 */
- (nullable ZDKORoomInfo *)roomInfo;

/**
 @brief Number of adults.
  */
- (nullable NSNumber *)numberOfAdults;

/**
 @brief Number of children.
  */
- (nullable NSNumber *)numberOfChildren;

/**
 @brief Additional guests.

@return Array of additional guests
  */
- (nullable NSArray <ZDKOGuest *> *)additionalGuests;

/**
 * @brief Returns true if breakfast is included in the reservation
 * @return True if is included, false if not included
 */
- (BOOL)isBreakfastIncluded;

/**
 * @brief Returns true if resrvation is checked in, but guest has access only to common areas
 * @return True if is soft checkin, false if properly checked in
 */
- (BOOL)isSoftCheckin;

/**
 * @brief Connected door zuid
 * @return Door zuid for the (first) door connected to the reservation or nil if no doors connected
 */
- (nullable NSString *)doorZuid;

/**
 * @brief Connected door title
 * @return Door title for the (first) door connected to the reservation or nil if no doors connected
 */
- (nullable NSString *)doorTitle;

/**
 @brief Connected door status
 
 @note
 UNDEFINED = 0,
 STORAGE = 10,
 COMMISSIONING = 20,
 PRODUCTION = 30,
 DEMO = 40,
 DISABLED = 50,
 ARCHIVED = 60
 
 @return Door status for the connected door.
 */
- (NSInteger)doorStatus;

#pragma mark General actions

/** @name Commonly used methods */

/**
 @brief Start the asynchronous flow to fetch the reservation from the PMS. Use this method to fetch latest updates on the reservation (for example, reservationStatereservation state).
 
 @param completeBlock ZDKOCurrentReservationResponseBlock
 */
- (void)fetchCurrentWithCompletion:(ZDKOCurrentReservationResponseBlock)completeBlock;

/**
 @brief Check in the reservation and issue a mobile key.

 @note When a check-in is initiated, the ZDK will pass the request to Zaplox
 backend services. Backend will look up communication path to the PMS of
 the hotel on which the reservation is valid. Backend will then request
 to check in the reservation with the PMS on the hotel. Outcome of the
 PMS check-in process is asynchronously reported to Zaplox backend. The
 status is periodically polled by ZDK and when known, returned
 asynchronously to caller. If checkin call is succesfull a mobile key is issues by the Zaplox BE.
 
 @param params        An arbitrary number of key value pairs as check-in parameters.
 @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)checkInWithParams:(nullable NSArray<NSDictionary*>*)params completion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
 @brief Check in the reservation wihout issuing a mobile key.

 @note When a check-in is initiated, the ZDK will pass the request to Zaplox
 backend services. Backend will look up communication path to the PMS of
 the hotel on which the reservation is valid. Backend will then request
 to check in the reservation with the PMS on the hotel. Outcome of the
 PMS check-in process is asynchronously reported to Zaplox backend. The
 status is periodically polled by ZDK and when known, returned
 asynchronously to caller.
 
 @note No key will be issued.
 
 @param params        An arbitrary number of key value pairs as check-in parameters.
 @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)checkInWithoutKeyWithCompletion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
 @brief Check out the reservation.

 @note When a checkout is initiated, the ZDK will pass the request to Zaplox
 backend services. Backend will look up communication path to the PMS of
 the hotel on which the reservation is valid. Backend will then request
 to check out the reservation with the PMS on the hotel. Outcome of the
 PMS checkout process is asynchronously reported to Zaplox backend. The
 status is periodically polled by ZDK and when known, returned
 asynchronously to caller.
 
 @param params        An arbitrary number of key value pairs as check-in parameters.
 @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)checkOutWithParams:(nullable NSArray<NSDictionary*>*)params completion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
 * @brief Start the asynchronous flow to update the primary guest associated
 * with the reservation.
 *
 * @param guest ZDKOGuest object to be updated. Can be retrieved with the method guest.
 * @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)updateGuest:(ZDKOGuest *)guest completion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
* @brief Start the asynchronous flow to update all guests associated
* with the reservation.
*
* @param guests  and array of ZDKOGuest objects to be updated.
* @param completeBlock ZDKOReservationActionResponseBlock
*/
- (void)updateAllGuests:(NSArray<ZDKOGuest*>*)guests completion:(ZDKOReservationActionResponseBlock)completeBlock;

/** @name Key sharing */

/**
 @brief Used to retrive a key from a shared reservation e.g. on a second device.

 @note On completion, call the method fetchKeysWithCompletion: on ZaploxManager, when done the key can be retreived with the instance method key as normal.
 
 @param token         The unique token associated with the reservation.
 @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)claimKeyWithShareToken:(NSString *)token completion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
 @brief Will associate the reservation with a token to make it's key shareable between devices.
 
 @param token         Any value as string. Be sure to make it unique since no validation will be performed on the value.
 @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)shareWithToken:(NSString *)token completion:(ZDKOReservationActionResponseBlock)completeBlock;

#pragma mark Room Assignment

/** @name Room assignment */

/**
 @brief Performs a check to see if a room has been assigned to the current instant of the reservation.
 */
- (BOOL)hasRoomAssigned;

/**
 * @brief Start the asynchronous flow to fetch available rooms relevant for this reservation.
 *
 * <p>See complete flow example in assignRoom:</p>
 *
 * @param completeBlock ZDKOFetchAvailableRoomsResponseBlock
 */
- (void)fetchAvailableRoomsWithCompletion:(ZDKOFetchAvailableRoomsResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to fetch room state for the room assigned to this reservation.
 * <p>
 * Note! If reservation doesn't have a room assigned, the fetch will fail.
 * <p>See hasRoomAssigned</p>
 * <p>See complete flow example in assignRoom:</p>
 *
 * @param completeBlock ZDKOFetchRoomsStateResponseBlock
 */
- (void)fetchRoomState:(ZDKOFetchRoomsStateResponseBlock)completeBlock;

/**
 * <p>
 * Start the asynchronous flow to assign a room to this reservation.
 * </p>
 * <p>
 * Availabe rooms can be fetched with fetchAvailableRooms:
 * </p>
 * <p>
 * An example of a full room assigment flow, that limits the number of heavy network calls
 * can be:
 * </p>
 * <blockquote>
 * <pre>
 * <code>
 *     if (myReservation hasRoomAssigned) {
 *         // In this case we just need to check if room is cleaned and inspected (ready for checkin, and key creation)
 *          [self fetchRoomState:^(ZDKRoomState state, ZDKError * __nullable error) {
 *              if (state == RoomStateInspected){
 *                  // Here we can start checkin process
 *              }
 *          }];
 *     } else {
 *          // No room assigned, hence we need to assign one
 *          [self fetchAvailableRoomsWithCompletion:^(NSArray<ZDKORoom *> * __nullable rooms, ZDKError * __nullable error) {
 *              // Select a room and assign the room.
 *          }];
 *     }
 * </code>
 * </pre>
 * </blockquote>
 *
 * @param room ZDKORoom
 * @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)assignRoom:(ZDKORoom*)room completion:(ZDKOReservationActionResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to unassign any room assigned to this reservation.
 *
 * @param completeBlock ZDKOReservationActionResponseBlock
 */
- (void)unassignRoomWithCompletion:(ZDKOReservationActionResponseBlock)completeBlock;

#pragma mark Payment

/** @name Payment */

/**
 * Start the asynchronous flow to fetch the ZDKODepositInfo associated
 * with the Reservation.
 *
 * @param completeBlock ZDKOFetchDepositInfoResponseBlock
 */
- (void)fetchDepositInfoWithCompletion:(ZDKOFetchDepositInfoResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to fetch the ZDKOFolio associated
 * with the Reservation.
 *
 * @param completeBlock ZDKOFetchFolioResponseBlock
 */
- (void)fetchFolioWithCompletion:(ZDKOFetchFolioResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a deposit payment for the reservation. This information can
 * be found in the ZDKODepositInfo object. See fetchDepositInfo:
 *
 * @param amount The amount to pay in the lowest monetary unit, example: 9.99 USD is noted as 999
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerDepositPayment:(NSNumber *)amount currency:(NSString *)currency completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a deposit payment for the reservation. This information can
 * be found in the ZDKODepositInfo object. See fetchDepositInfo:
 *
 * @param amount The amount to pay in the lowest monetary unit, example: 9.99 USD is noted as 999
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param parameters Set of  custom parameters (key/values) used by payment providers
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerDepositPayment:(NSNumber *)amount currency:(NSString *)currency parameters:(NSDictionary *)parameters completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a payment for the reservation. This information can
 * be found in the ZDKOFolio object. See fetchFolio:
 *
 * @param paymentWindows An array of ZDKOPaymentWindow describing amount for each window in the PMS
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerPayment:(NSArray<ZDKOPaymentWindow *> *)paymentWindows currency:(NSString *)currency completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a payment for the reservation. This information can
 * be found in the ZDKOFolio object. See fetchFolio:
 *
 * @param paymentType ZDKPaymentType - Pay, Authorize, Capture, Tokenize
 * @param paymentWindows An array of ZDKOPaymentWindow describing amount for each window in the PMS
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerPayment:(NSArray<ZDKOPaymentWindow *> *)paymentWindows withType:(ZDKPaymentType)paymentType currency:(NSString *)currency completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a payment for the reservation. This information can
 * be found in the ZDKOFolio object. See fetchFolio:
 *
 * @param paymentWindows An array of ZDKOPaymentWindow describing amount for each window in the PMS
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param parameters Set of  custom parameters (key/values) used by payment providers
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerPayment:(NSArray<ZDKOPaymentWindow *> *)paymentWindows currency:(NSString *)currency parameters:(NSDictionary *)parameters completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to register a payment for the reservation. This information can
 * be found in the ZDKOFolio object. See fetchFolio:
 *
 * @param paymentOperation ZDKPaymentType - Pay, Authorize, Capture, Tokenize
 * @param paymentWindows An array of ZDKOPaymentWindow describing amount for each window in the PMS
 * @param currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 * @param parameters Set of  custom parameters (key/values) used by payment providers
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)registerPayment:(NSArray<ZDKOPaymentWindow *> *)paymentWindows withType:(ZDKPaymentType)paymentType currency:(NSString *)currency parameters:(NSDictionary *)parameters completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
 * Start the asynchronous flow to make a payment for the reservation, a process started by registerPayment:
 *
 * @param paymentZuid Id of payment registered in previous step. See registerPayment:
 * @param completeBlock ZDKOPaymentResponseBlock
 */
- (void)makePayment:(NSString *)paymentZuid completion:(ZDKOPaymentResponseBlock)completeBlock;

/**
* Registers a user signature for the reservation in the Zaplox backend.
*
* @param imageData NSData PNG image data containing the signature
* @param ziud NSString Reservation zuid
* @param completeBlock ZDKOReservationActionResponseBlock
*/
+ (void)registerSignature:(NSData *)imageData forReservationZuid:(NSString *)zuid completion:(ZDKOReservationActionResponseBlock)completeBlock;

@end


/**
 @brief Representation of a Reservation in the Zaplox system.
 */
@interface ZDKOReservation : ZDKObject <ZDKReservation>

@property (nonatomic) NSArray *objectLinks;
@property (nonatomic) NSString *siteZuid;
@property (nullable, nonatomic) NSString *roomUnitId;
@property (nullable, nonatomic) NSString *preferredRoomNumber;

/*
 @brief Will attempt to claim a reservation by making a put request to the backend.

 @param reservationId The id of the reservation to be claimed.
 @param completeBlock ZDKCompletionBlock
 */
+ (void)claimById:(NSString *)reservationId completion:(ZDKCompletionBlock)completeBlock;

/*
 @brief Will attempt to unclaim a reservation by making a put request to the backend.

 @param reservationId The id of the reservation to be unclaimed.
 @param completeBlock ZDKCompletionBlock
 */
+ (void)unclaimById:(NSString *)reservationId completion:(ZDKCompletionBlock)completeBlock;

- (void)shareKey:(NSString *)keyZuid identity:(NSString *)identity code:(NSString *)code completion:(ZDKCompletionBlock)completeBlock;
- (void)setRoomInfo:(ZDKORoomInfo *)roomInfo;

- (void)registerToken:(NSString *)token forPayment:(NSString *)paymentZuid completion:(ZDKOReservationActionResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
