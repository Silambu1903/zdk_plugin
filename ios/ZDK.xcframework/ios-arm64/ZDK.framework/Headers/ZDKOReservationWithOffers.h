//
//  ReservationsAndOffers.h
//  Pods
//
//  Created by David Aberg on 03/09/15.
//
//
@class ZDKOReservationWithOffers;

#import "ZDKObject.h"
#import "ZDKOOffer.h"
#import "ZDKOReservation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox object ReservationWithOffers.
 */
@interface ZDKOReservationWithOffers : ZDKObject

@property(nonatomic) ZDKOReservation *reservation;
@property(nonatomic) ZDKOOffer *mainOffer;
@property(nonatomic) NSArray *linkedOffers;

@end

NS_ASSUME_NONNULL_END
