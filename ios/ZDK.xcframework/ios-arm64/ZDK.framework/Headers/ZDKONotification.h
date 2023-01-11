//
//  ZDKONotification.h
//  Pods
//
//  Created by David Aberg on 07/03/16.
//
//

#import "ZDKOOffer.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKONotification : ZDKOOffer

+ (void)getNotificationsByReservationZuids:(NSArray *)reservationZuids cachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOOffersResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
