//
//  ZDKOAliceDetails.h
//  ZDK
//
//  Created by Kevin Henriksson on 2022-07-03.
//  Copyright © 2022 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Resource info object.
 */
@protocol ZDKAliceDetails

/** @name Properties */

/**
 @brief Alice API password.
 */
@property (nullable, nonatomic, readonly) NSString *password;

/**
 @brief Is Alice chat enabled.
 */
@property (nonatomic, readonly) BOOL enabled;

/**
 @brief Alice API private key.
 */
@property (nullable, nonatomic, readonly) NSString *privateKey;

/**
 @brief Name of Alice chat.
 */
@property (nullable, nonatomic, readonly) NSString *chatServiceName;

/**
 @brief Type of Alice chat environment. (i.e sandbox etc).
 */
@property (nullable, nonatomic, readonly) NSString *environment;

/**
 @brief Hotel Id for Alice chat.
 */
@property (nullable, nonatomic, readonly) NSString *hotelId;

/**
 @brief Client username for Alice chat.
 */
@property (nullable, nonatomic, readonly) NSString *username;

@end


@interface ZDKOAliceDetails : ZDKObject <ZDKAliceDetails>

@end

NS_ASSUME_NONNULL_END
