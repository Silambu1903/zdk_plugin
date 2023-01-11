//
//  ZDKOObjectLink.h
//  Pods
//
//  Created by David Aberg on 25/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/*
 @brief Protocol of the Zaplox Object Link object.
 */
@protocol ZDKObjectLink
/* @name Properties */

/*
 @brief Type of object. Example ```"KEY", "DOOR"```
 */
- (NSString *)object;

/*
 @brief The unique identifier of the object.
 */
- (NSString *)zuid;

@end

@interface ZDKOObjectLink : ZDKObject <ZDKObjectLink>

@end

NS_ASSUME_NONNULL_END
