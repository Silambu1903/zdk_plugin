//
//  ZDKORoom.h
//  ZDK
//
//  Created by David Aberg on 2017-07-11.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Room in the Zaplox system.
 */
@protocol ZDKRoom

/** @name Properties */

/**
 @brief Room id
 */
- (nullable NSString *)number;

/**
 @brief The room state of this room, when the request was done. To get the latest state, use {@link ZDKReservation#fetchRoomState:(nonnull ZDKOFetchRoomsStateResponseBlock)completeBlock}
 @return ZDKRoomState
 */
- (ZDKRoomState)state;

@end

/**
 @brief Representation of a Room in the Zaplox system.
 */
@interface ZDKORoom : ZDKObject <ZDKRoom>

- (void)setState:(NSString *)roomState;

@end

NS_ASSUME_NONNULL_END
