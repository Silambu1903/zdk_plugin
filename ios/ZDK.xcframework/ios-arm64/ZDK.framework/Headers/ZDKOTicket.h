//
//  ZDKOTicket.h
//  ZDK
//
//  Created by David Aberg on 2017-10-06.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Ticket object.
 */
@interface ZDKOTicket : ZDKObject

@property (nullable, nonatomic, readonly) NSString *info;
@property (nullable, nonatomic, readonly) NSString *facilityName;
@property (nullable, nonatomic, readonly) NSString *status;
@property (nullable, nonatomic, readonly) NSString *ticketId;
@property (nullable, nonatomic, readonly) NSString *ticketType;

/** @name Type methods */

/**
 @brief Performs a get request to the backend to retrive an array of offers.

 @param reservationId Reservation Zuid
 @param siteId        Site Zuid
 @param cachePolicy   ZDKCachePolicy
 @param completeBlock ZDKOOffersResponseBlock
 */
+ (void)getTicketsByReservationId:(NSString *)reservationId siteId:(NSString *)siteId cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOTicketsResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
