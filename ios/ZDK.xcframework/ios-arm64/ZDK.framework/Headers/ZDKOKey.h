//
//  Key.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import "ZDKObject.h"
#import "ZDKOKeyDetails.h"
#import "ZDKOKeyEncryption.h"
#import "ZDKOKeyContents.h"
#import "ZDKConstantsAndEnums.h"
#import "ZDKODoor.h"
#import "ZDKLockVendor.h"

/**
 *  Enumeration to describe different types of lock methods in the ZDK.
 */
typedef NS_ENUM(NSInteger, ZDKUnlockMethod) {
    /**
     * @brief Key unlocks via BLE, and lock is awakened by proximity.
     */
    ZDKUnlockMethodBleProximity,
    
    /**
     * @brief Key unlocks via network call
     */
    ZDKUnlockMethodOnline
};

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a generic key in the Zaplox system. It includes the underlying mechanism for synchronization of keys from lock providers to the Zaplox cloud. Could be of any manufacturer type.
 */
@protocol ZDKKey

/** @name Properties */

/**
 * @brief Check is the key is an original key or a shared key
 * @return True if is original, false if is shared
 */
- (BOOL)isOriginal;

/**
 * @brief Check is the key can be shared
 * @return True if can be shared, false if not
 */
- (BOOL)isShareable;

/**
* @brief Key state
* @return KeyState
*/
- (ZDKKeyState)keyState;

/**
 @brief Validity start date

 @return Validity start date for the key
*/
- (NSDate *)validityStart;

/**
 @brief Validity end date

 @return Validity end date for the key
*/
- (NSDate *)validityEnd;

/**
 @brief The unique identifier of this key.
 */
- (NSString *)keyZuid;

/**
 @brief The unique identifier of the site for this key.
 */
- (NSString *)siteZuid;

/**
 @brief Doors connected to this key.
 @return A list of ZDKODoor.
 */
- (NSArray<ZDKODoor *> *)doors;

/**
 * @brief The vendor supplying the key.
 *
 * @return ZDKLockVendor
 */
- (ZDKLockVendor)lockVendor;

/** @name Unlock methods */

/**
 * @brief The opening method for the key.
 *
 * @return ZDKUnlockMethod
 */
- (ZDKUnlockMethod)unlockMethod;

/**
 @brief Performs an unlock attempt on the keys primary door.

 @note When unlock is called, the ZDK will match the internal key
 representation to an internal 3rd party lock vendor mobile key library
 and initiate a door unlock on the matching library. The internal mobile
 key library will then initiate vendor specific Bluetooth communication
 with the lock to open the door.

 For this to be successful, Bluetooth must be enabled in
 phone and main app must be allowed to access Bluetooth.
 
 @param completeBlock ZDKOKeyUnlockResponseBlock
 */
- (void)unlockWithCompletion:(ZDKOKeyUnlockResponseBlock)completeBlock;

/**
 @brief Only applicable for Zaplox and Zaplox V2 locks. Performs an unlock attempt on a specific door.

 @note Only applicable for Zaplox and Zaplox V2 locks. When unlock is called, the ZDK will match the internal key
 representation to an internal 3rd party lock vendor mobile key library
 and initiate a door unlock on the matching library. The internal mobile
 key library will then initiate vendor specific Bluetooth communication
 with the lock to open the door.

 For this to be successful, Bluetooth must be enabled in
 phone and main app must be allowed to access Bluetooth.
 @see unlockWithCompletion:
 
 @param doorZuid      id of the door to be unlocked.
 @param completeBlock ZDKOKeyUnlockResponseBlock
 */
- (void)unlockDoor:(NSString *)doorZuid withCompletion:(nonnull ZDKOKeyUnlockResponseBlock)completeBlock;

/**
 @brief Canceles an ongoing unlock attempt.

 @note Stops Bluetooth scanning. Depending on the application design this method can be called when the key should not be active.
 Only supported by Dorma Kaba keys.
 */
- (void)stopUnlock;

@end

/**
 @brief Represents a generic Key in the Zaplox system. Could be of any manufacturer type.
 */
@interface ZDKOKey : ZDKObject <ZDKKey>

+ (NSArray<ZDKOKey *> *)getAllActiveCached;

@property (nonatomic, readonly) NSInteger state;
@property (nonatomic, readonly) ZDKOKeyDetails *keyDetails;
@property (nonatomic, readonly) NSInteger shareDepth;

@end

NS_ASSUME_NONNULL_END
