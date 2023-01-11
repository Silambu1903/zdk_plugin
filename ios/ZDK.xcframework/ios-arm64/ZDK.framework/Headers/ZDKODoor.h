//
//  ZDKODoor.h
//  Pods
//
//  Created by David Aberg on 07/10/15.
//
//

#import "ZDKObject.h"
#import "ZDKODoorDetails.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Representation of a Door connected to a Key.
 */
@protocol ZDKDoor

/** @name Properties */

/**
 @brief The unique Zaplox Identifier for the Door.
 */
@property (nonatomic, readonly) NSString *doorZuid;

/**
 @brief Door title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 @brief Door details.
 */
@property (nonatomic, readonly) ZDKODoorDetails *doorDetails;

@end

/**
 @brief Represents a Door connected to a Key.
 */
@interface ZDKODoor : ZDKObject <ZDKDoor>

+ (void)getByZuid:(NSString *)zuid completion:(ZDKODoorResponseBlock)completeBlock;
+ (nullable ZDKODoor *)getCachedByZuid:(NSString *)zuid;

@end

NS_ASSUME_NONNULL_END
