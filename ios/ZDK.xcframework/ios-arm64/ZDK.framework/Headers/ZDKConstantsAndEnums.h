//
//  ZDKConstantsAndEnums.h
//  Pods
//
//  Created by David Aberg on 12/10/15.
//
//

#import <Foundation/Foundation.h>

#import <os/log.h>

@class ZaploxManager;
@class ZDKOReservation;
@class ZDKOKey;
@class ZDKOReservationWithOffers;
@class ZDKError;
@class ZDKOSite;
@class ZDKORoom;
@class ZDKOPayment;
@class ZDKOFolio;
@class ZDKODepositInfo;
@class ZDKOTicket;
@class ZDKODoor;
@class ZDKOCustomer;
@protocol ZaploxManagerProtocol;

/**
 * When setup has finished one of the following status will be returned.
 */
typedef NS_ENUM(NSInteger, ZDKSetupStatus) {
    /**
     @brief Setup finished successfully.
     */
    ZDKSetupStatusSetupSuccess,
    /**
     @brief ZDK is already setup.
     */
    ZDKSetupStatusAlreadySetup,
    /**
     @brief Someting went wrong during setup.
     */
    ZDKSetupStatusSetupFailed
};

/**
 *  Enumeration to describe different types of errors that may occur in the ZDK.
 */
typedef NS_ENUM(NSInteger, ZDKErrorCode) {
    /**
     *  No internetr.
     */
    ZDK_ERROR_NO_INTERNET = 100,
    /**
     *  Unknown error.
     */
    ZDK_ERROR_UNKNOWN = 101,
    /**
     *  Indicates a problem with network or connections.
     */
    ZDK_ERROR_CONNECTION = 102,
    /**
     *  ZDK functionality was used without a successful setup.
     */
    ZDK_ERROR_NOT_INITIALIZED = 103,
    /**
     *  Indicates problem related to Bluetooth.
     */
    ZDK_ERROR_BLUETOOTH = 104,
    /**
     *  Unlock call on door not connected to the Key.
     */
    ZDK_ERROR_INVALID_DOOR = 105,
    /**
     *  Request timed out, or polled too many attempts.
     */
    ZDK_ERROR_TIME_OUT = 106,
    /**
     *  Indicates a problem during the unlock process, related to Keystores or 3rd party lock vendor functionality.
     */
    ZDK_ERROR_UNLOCK = 107,
    /**
     *  Asynchronous work is already in progress.
     */
    ZDK_ERROR_SERVICE_BUSY = 108,
    /**
     *  Failure during setup with third party key service.
     */
    ZDK_ERROR_TPK_SETUP = 109,
    /**
     *  Failure during syncronization of third party key service.
     */
    ZDK_ERROR_TPK_SYNC = 110,
    /**
    * The room that was attempted to be assigned was occupied or already assigned.
    */
    ZDK_ERROR_ROOM_ALREADY_ASSIGNED = 111,
    /**
    * The room that was attempted to be assigned is missing, invalid or in some way not available for assignment.
    */
    ZDK_ERROR_INVALID_ROOM = 112,
    /**
    * A different room (of same category) was assigned, instead of the room attempted to be assigned.
    */
    ZDK_ERROR_ALTERNATIVE_ROOM_ASSIGNED = 113,
    /**
    * Something went wrong during assignment of the room.
    */
    ZDK_ERROR_ASSIGN = 114,
    /**
    * The method is not available in this configuration or PMS system.
    */
    ZDK_ERROR_MISSING_FUNCTION_IN_CONFIGURATION = 115,
    /**
    * The reservation has no room assigned.
    */
    ZDK_ERROR_NO_ROOM_ASSIGNED = 116,
    /**
     *  Device has been deactivated from Zaplox system as a security precaution, and can no longer be used.
     */
    ZDK_ERROR_DEVICE_INVALID = 117,
    /**
     * Unlock was rejected by third party lock. Key is not valid.
     */
    ZDK_UNLOCK_REJECTED = 118,
    /**
     * Unlock attempt was stopped or interrupted.
     */
    ZDK_UNLOCK_INTERRUPTED = 119,
    /**
     *  Reservation not found.
     */
    ZDK_ERROR_RESERVATION_NOT_FOUND = 121,
    /**
     *  Some keys failed during syncronization of third party key service.
     */
    ZDK_ERROR_TPK_SYNC_INCOMPLETE = 126,
    /**
     *  Reservation not found.
     */
    ZE_BACKEND_PMS_WORKER__RESERVATION_NOT_FOUND_ERROR = 201,
    /**
     *  Failed to create key.
     */
    ZE_BACKEND_PMS_WORKER__CREATE_KEY_ERROR = 202,
    /**
     *  No reservations match, even though check-in is set to success.
     */
    ZE_BACKEND_PMS_WORKER__NO_RESERVATION_MATCH = 203,
    /**
     *  Reservation room does not match any door(s).
     */
    ZE_BACKEND_PMS_WORKER__NO_ROOMS = 204,
    /**
     *  Could not get site.
     */
    ZE_BACKEND_PMS_WORKER__NO_SITE = 205,
    /**
     *  Reservation not in relevant state.
     */
    ZE_BACKEND_PMS_WORKER__WRONG_STATE = 206,
    /**
     *  Could not find account.
     */
    ZE_BACKEND_PMS_WORKER__NO_ACCOUNT = 207,
    /**
     *  Missing reference.
     */
    ZE_BACKEND_PMS_WORKER__NO_REFERENCE = 208,
    /**
     *  Reservation not found.
     */
    ZE_BACKEND_RESERVATION_SERVICE__RESERVATION_NOT_FOUND = 209,
    /**
     *  Reservation transaction not found.
     */
    ZE_BACKEND_RESERVATION_SERVICE__RESERVATION_TRANSACTION_NOT_FOUND = 210,
    /**
     *  Invalid share token.
     */
    ZE_BACKEND_PMS_WORKER__INVALID_TOKEN = 211,
    /**
     *  Can't share reservation, master key is missing.
     */
    ZE_BACKEND_PMS_WORKER__NO_MASTER_KEY = 212,
    /**
     *  Can't share reservation.
     */
    ZE_BACKEND_PMS_WORKER__CLONE_KEY_ERROR = 213,
    /**
     *  Communication with PMS timed out/PMS not accessible.
     */
    ZE_PMS_COMMUNICATION_TIMEOUT = 301,
    /**
     *  Some parameters necessary to perform search was not provided.
     */
    ZE_PMS_FIND_INSUFFICENT_PARAMETERS = 302,
    /**
     *  PMS configured to require some kind of payment guarantee which is missing.
     */
    ZE_PMS_CHECKIN_MISSING_GUARANTEE = 303,
    /**
     *  PMS requires room to be assigned before check-in.
     */
    ZE_PMS_CHECKIN_ROOM_NOT_ASSIGNED = 304,
    /**
     *  One or more required fields missing.
     */
    ZE_PMS_CHECKIN_INCOMPLETE_GUEST_PROFILE = 305,
    /**
     *  Required guest document, i.e. passport, is missing on reservation/profile.
     */
    ZE_PMS_CHECKIN_MISSING_GUEST_DOCUMENT = 306,
    /**
     *  Unknown/not specified error occured during check-in process.
     */
    ZE_PMS_CHECKIN_UNKNOWN = 307,
    /**
     *  ZCP configured to require full payment before checkout.
     */
    ZE_PMS_CHECKOUT_NOT_PAID = 308,
    /**
     *  ZCP configured to handle payment, payment failed.
     */
    ZE_PMS_PAYMENT_ERROR = 309,
    /**
     *  Attempt to check out before end-of-stay date.
     */
    ZE_PMS_CHECKOUT_TOO_EARLY = 310,
    /**
     *  Unknown/not specified error occured during checkout process.
     */
    ZE_PMS_CHECKOUT_UNKNOWN = 311,
    /**
     *  ZCP configuration error.
     */
    ZE_ZCP_CONFIGURATION_ERROR = 401,
    /**
     *  ZCP generic internal module error.
     */
    ZE_ZCP_MODULE_ERROR = 402
};

/**
 * An unlock attempt can result in the following states.
 */
typedef NS_ENUM(NSInteger, ZDKUnlockState) {
    /**
     @brief The unlock was created.
     */
    ZDKUnlockStateCreated,
    /**
     @brief The unlock attempt was successfull.
     */
    ZDKUnlockStateSuccess,
    /**
     @brief The phone received an unauthorized code.
     */
    ZDKUnlockStateRejected,
    /**
     @brief An error occured when unlocking.
     */
    ZDKUnlockStateError,
    /**
     @brief The key has been expired.
     */
    ZDKUnlockStateExpired,
    /**
     @brief The unlock attempt timed out before retriving any response from the lock.
     */
    ZDKUnlockStateTimeOut
};

/**
 * Representation of the state of a Room This state controls if Room and Reservation is ready for checkin.
 */
typedef NS_ENUM(NSInteger, ZDKRoomState) {
    /**
     @brief Roome state unknown.
     */
    ZDKRoomStateUnknown,
    /**
     @brief Room is dirty.
     */
    ZDKRoomStateDirty,
    /**
     @brief Room is clean.
     */
    ZDKRoomStateClean,
    /**
     @brief Room is inspected.
     */
    ZDKRoomStateInspected
};

/**
 The purpose of ZDKCachePolicy is to simplify the cache handling in the frontend layer.
 When calling a method with cachePolicy as argument the resulting callback block can be altered to different needs.
 */
typedef NS_ENUM(NSInteger, ZDKCachePolicy) {
    /**
     The block will first return the most recent cached result. Later, the result of the network request.
     */
    ZDKCachePolicyCachedThenNetwork,
    /**
     The block will only return the cached result.
     */
    ZDKCachePolicyCachedOnly,
    /**
     Will attempt to do a network request and return the result in the block.
     If the request failed the most recent cached result will be returned instead.
     */
    ZDKCachePolicyNetworkElseCached,
    /**
     Will only return the result of the network request in the block.
     */
    ZDKCachePolicyNetworkOnly
};

/**
 * State of reservation.
 */
typedef NS_ENUM(NSInteger, ZDKOReservationState) {
    /**
     @brief Payment method not verified.<p>
     */
    ZDKOReservationStateUnauthorised,
    /**
     @brief Payment method verified.<p>
     */
    ZDKOReservationStateAuthorized,
    /**
     @brief Room assigend in PMS.<p>
     */
    ZDKOReservationStateRoomAssigned,
    /**
     @brief Reservation checked in.<p>
     */
    ZDKOReservationStateCheckedIn,
    /**
     @brief Most common checked-in state.<p>
     */
    ZDKOReservationStateInhouse,
    /**
     @brief Reservation checked out.<p>
     */
    ZDKOReservationStateCheckedOut,
    /**
     @brief Reservation unhandled.<p>
     */
    ZDKOReservationStateUnhandledReservation,
    /**
     @brief Zaplox direct awaiting check-in.<p>
     */
    ZDKOReservationStatePendingCheckIn,
    /**
     @brief Pre-checkin before PMS check-in.<p>
     */
    ZDKOReservationStatePreCheckIn,
    /**
     @brief Zaplox direct awaiting check-out.<p>
     */
    ZDKOReservationStatePendingCheckOut
};

/**
 @brief When setup has finished one of the following status will be returned.
 */
typedef NS_ENUM(NSInteger, ZDKKeyState) {
    /**
     @brief Key is created.
     Key has been created and assigned to a device. In this state the Zaplox backend is waiting for the device to begin fetching keys. The fetch function provided in the SDK involves communication with the Key provider in order to setup the device for receiving keys, communication with the Zaplox backend to trigger key creation at the lock server and finally retrieving the created key from the key provider.
     */
    ZDKKeyStateCreated,
    /**
     @brief Key is claimed by account and downloaded to mobile app.
     Zaplox backend has synced keys against the key provider and removed any revoked keys.
     */
    ZDKKeyStateClaimed,
    /**
     @brief Key is active and can be used.
     */
    ZDKKeyStateActive,
    /**
     @brief Key cannot be used as it has been rejected by unlocker.
     The key has been successfully created on the key server, is synced from the Zaplox backend and is now downloaded to the app and activated. The app has also done a callback to Zaplox backend to acknowledge and register the key as active.
     */
    ZDKKeyStateRejected,
    /**
     @brief Key is revoked from issuer.
     Key is revoked from the Lock server and will be invalid as soon as the zdk syncs to the Key provider.
     */
    ZDKKeyStateRevoked,
    /**
     @brief Key is ready to be reclaimed by account.
     */
    ZDKKeyStateForreclaim,
    /**
     @brief Key is requested to be created via a Zaplox Connection Point.
     This means that the app has triggered the fetch function through the ZDK which in turn has triggered a request to contact the Lock server via our connection point. At this point we know the request is sent from the Zaplox backend to the connection point running alongside the key server.
     */
    ZDKKeyStatePendingExternalCreateRequest,
    /**
     @brief Key has been requested to be created in third party system.
     The request to create a key has gone from our connection point to the Lock server, at this point we are waiting for the key to be finalized in the lock server and registered at the Key provider. Once this is done the app can sync the key and activate it.
     */
    ZDKKeyStatePendingExternalCreate,
    /**
     @brief Key is requested to be deleted via a Zaplox Connection Point.
     Same as 'Pending External Create Request' but for revoking keys. e.g the revoke key request has successfully been sent to the key connection point.
     */
    ZDKKeyStatePendingExternalDeleteRequest,
    /**
     @brief Key has been requested to be deleted in third party system.
     Same as 'Pending External Create' but for revoking keys. e.g the revoke key request has successfully been sent to the Key server.
     */
    ZDKKeyStatePendingExternalDelete,
    /**
     @brief Key is awaiting a claim after been received from third party.
     Key sync is initialized and ongoing.
     */
    ZDKKeyStatePendingClaim,
    /**
     @brief Key failed to be created/deleted via Zaplox Connection Point.
     This state means that something has went wrong either in the key connection point, the lock server or the key provider. Most likely due to bad connections between the systems or one of the systems being down.
     */
    ZDKKeyStateErrorRemote,
    /**
     @brief Key cannot be created as device is missing.
     */
    ZDKKeyStateErrorNoDevice,
    /**
     @brief Key is not mobile but a key card.
     This state means the key is a key card and not a mobile key.
     */
    ZDKKeyStateCardActive,
    /**
     @brief Unknown state.
     */
    ZDKKeyStateUnknown
};

/**
 * Enumeration for payment type.
 */
typedef NS_ENUM(NSInteger, ZDKPaymentType) {
    /**
     @brief Payment.
     */
    ZDKPaymentTypePay,
    /**
     @brief Authorization.
     */
    ZDKPaymentTypeAuthorize,
    /**
     @brief Capture.
     */
    ZDKPaymentTypeCapture,
    /**
     @brief Tokenize.
     */
    ZDKPaymentTypeTokenize
};

/**
 @brief The default block used for completion handling in the ZDK.
 *
 @param result           The result of the operation. Could be either NSArray or NSDictionary.
 @param error            ZDKError
 @param isCachedResponse BOOL @see ZDKCachePolicy
 */
typedef void (^ZDKCompletionBlock)(id __nullable result, ZDKError  * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition. Will be used in conjunction with the ZDK setup.
 
 @param statusCode    ZDKSetupStatus
 @param zaploxManager ZaploxManager
 @param error         ZDKError
 */
typedef void (^ZDKSetupResponseBlock)(ZDKSetupStatus statusCode, id<ZaploxManagerProtocol> __nullable zaploxManager,  ZDKError * __nullable error);

/**
 @brief This block will be used as completion handling when signing in.
 
 @param changePwdRequired BOOL
 @param error             ZDKError
 */
typedef void (^ZDKLoginResponseBlock)(ZDKError * __nullable error, BOOL changePwdRequired);

/**
 @brief Reservations result block
 *
 @param reservations NSArray
 @param error        ZDKError
 */
typedef void (^ZDKOReservationsResponseBlock)(NSArray<ZDKOReservation*> * __nullable reservations, ZDKError * __nullable error);

/**
 @brief Reservation result block
 *
 @param reservation      ZDKOReservation
 @param error            ZDKError
 @param isCachedResponse BOOL {@see ZDKCachePolicy}
 */
typedef void (^ZDKOReservationResponseBlock)(ZDKOReservation  * __nullable reservation, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Fetch current reservation result block
 *
 @param reservation      ZDKOReservation
 @param error            ZDKError
 */
typedef void (^ZDKOCurrentReservationResponseBlock)(ZDKOReservation  * __nullable reservation, ZDKError * __nullable error);


/**
 @brief Reservation action result block
 *
 @param error            ZDKError
 */
typedef void (^ZDKOReservationActionResponseBlock)(ZDKError * __nullable error);

/**
 @brief Fetch reservation properties result block
 *
 @param properties       NSDictionary
 @param error            ZDKError
 */
typedef void (^ZDKOFetchReservationPropertiesResponseBlock)(NSDictionary * __nullable properties, ZDKError * __nullable error);

/**
 @brief Fetch folio result block
 *
 @param folio            ZDKOFolio
 @param error            ZDKError
 */
typedef void (^ZDKOFetchFolioResponseBlock)(ZDKOFolio * __nullable folio, ZDKError * __nullable error);

/**
 @brief Fetch deposit info result block
 *
 @param depositInfo      ZDKODepositInfo
 @param error            ZDKError
 */
typedef void (^ZDKOFetchDepositInfoResponseBlock)(ZDKODepositInfo * __nullable depositInfo, ZDKError * __nullable error);

/**
 @brief Register payment result block
 *
 @param payment          ZDKOPayment
 @param error            ZDKError
 */
typedef void (^ZDKOPaymentResponseBlock)(ZDKOPayment * __nullable payment, ZDKError * __nullable error);

/**
 @brief Available rooms result block
 *
 @param rooms            ZDKORoom
 @param error            ZDKError
 */
typedef void (^ZDKOFetchAvailableRoomsResponseBlock)(NSArray<ZDKORoom*> * __nullable rooms, ZDKError * __nullable error);

/**
 @brief Room state result block
 *
 @param state            ZDKRoomState
 @param error            ZDKError
 */
typedef void (^ZDKOFetchRoomsStateResponseBlock)(ZDKRoomState state, ZDKError * __nullable error);

/**
 @brief Block definition
 *
 @param keys             NSArray<ZDKOKey> ZDKOKey
 @param error            ZDKError
 @param isCachedReponse  BOOL
 */
typedef void (^ZDKOKeysResponseBlock)(NSArray<ZDKOKey*> * __nullable keys, ZDKError * __nullable error, BOOL isCachedReponse);

/**
 @brief Block definition
 *
 @param keys             NSArray<ZDKOKey> ZDKOKey - all keys found. The array may contain invalid and inactive keys. Please, use the property keyState to check the state if you're useing keys from the response. Otherwise, use methods keys() on ZaploxManager or ZDKOReservation.
 @param error            ZDKError
 */
typedef void (^ZDKOFetchKeysResponseBlock)(NSArray<ZDKOKey*> * __nullable keys, ZDKError * __nullable error);

/**
 @brief Block definition
 
 @param reservationWithOffers ZDKOReservationWithOffers
 @param error                 ZDKError
 @param isCachedResponse      BOOL {@see ZDKCachePolicy}
 */
typedef void (^ZDKOReservationWithOffersResponseBlock)(ZDKOReservationWithOffers * __nullable reservationWithOffers, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param reservationsWithOffers NSArray<ZDKOReservationWithOffers>
 @param error                  ZDKError
 @param isCachedResponse       BOOL {@see ZDKCachePolicy}
 */
typedef void (^ZDKOReservationsWithOffersResponseBlock)(NSArray<ZDKOReservationWithOffers*> * __nullable reservationsWithOffers, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param response  NSDictionary
 @param error   ZDKError
 */

typedef void (^ZDKOKeyUnlockResponseBlock)(NSDictionary * __nullable response, ZDKError * __nullable error);

/**
 @brief Block definition
 
 @param state Unlockstate
 @param error ZDKError
 */
typedef void (^ZDKOKeyOnlineUnlockStatusResponseBlock)(ZDKUnlockState state, ZDKError * __nullable error);

/**
 @brief Block definition
 
 @param sites            NSArray<ZDKOSite> ZDKOSite
 @param error            ZDKError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKOSitesResponseBlock)(NSArray<ZDKOSite*> * __nullable sites, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param tickets          NSArray<ZDKOTicket> ZDKOTicket
 @param error            ZDKError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKOTicketsResponseBlock)(NSArray<ZDKOTicket*> * __nullable tickets, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param site             ZDKOSite
 @param error            ZDKError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKOSiteResponseBlock)(ZDKOSite * __nullable site, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 *
 @param key            ZDKOKey
 @param error          ZDKError
 */
typedef void (^ZDKOKeyResponseBlock)(ZDKOKey * __nullable key, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param door             ZDKODoor
 @param error            ZDKError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKODoorResponseBlock)(ZDKODoor * __nullable door, ZDKError * __nullable error, BOOL isCachedResponse);

/**
 @brief Block definition
 
 @param site             ZDKOCustomer
 @param error            ZDKError
 @param isCachedResponse BOOL
 */
typedef void (^ZDKOCustomerResponseBlock)(ZDKOCustomer * __nullable customer, ZDKError * __nullable error, BOOL isCachedResponse);
