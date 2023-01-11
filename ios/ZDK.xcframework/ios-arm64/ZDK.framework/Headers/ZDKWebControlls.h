//
//  ZDKWebControlls.h
//  ZDK
//
//  Created by David Aberg on 10/10/16.
//  Copyright © 2016 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKWebControlls : NSObject


/**
 @brief Generates a url to be used when choosing in a reservation
 *
 @param reservationIds    The ids of the reservations of which one should be chosen.
 *
 @return A url to be used to choose a reservation with a webview.
 */
+ (NSURL *)chooseURLForReservationIds:(NSArray *)reservationIds;

/**
 @brief Generates a url to be used when checking in a reservation
 *
 @param reservationId    The id of the reservation which should be checked in.
 *
 @return A url to be used when checking in a reservation with a webview.
 */
+ (NSURL *)checkInURLForReservationId:(NSString *)reservationId;


/**
 @brief Generates a url to be used when checking out a reservation
 *
 @param reservationId    The id of the reservation which should be checked out.
 *
 @return A url to be used when checking out a reservation with a webview.
 */
+ (NSURL *)checkOutURLForReservationId:(NSString *)reservationId;


/**
 @brief Generates a url to be used when upgrading an offer.
 *
 @param uri              The process uri override tied to the offer.
 @param offerId          The id of the offer.
 @param reservationId    The id of the reservation connected to the offer.
 *
 @return  url to be used when upgrading an offer with a webview.
 */
+ (NSURL *)customOfferURI:(NSString *)uri forOfferWithId:(NSString *)offerId onReservationWithId:(NSString *)reservationId;


/**
 @brief Generates a url to be used to add an offer to a reservation
 *
 @param offerId       The id of the offer.
 @param reservationId The id of the reservation connected to the offer.
 *
 @return url to be used when adding an offer to a reservation with a webview.
 */
+ (NSURL *)addOfferWithId:(NSString *)offerId toReservationWithId:(NSString *)reservationId;


/**
 @brief Generates a url to be used when booking a new reservation.
 *
 @param siteId   The site on which to make the booking.
 *
 @return url to be used when booking a new reservation with a webview.
 */
+ (NSURL *)newReservationBySiteId:(NSString *)siteId;


/**
 @brief Generates a url to be called when a reservation is checked in but don't have any key
 *
 @param reservationId    The id of the reservation that needs a key.
 *
 @return url to be used when creating a key to a reservation with a webview.
 */
+ (NSURL *)createKeyToReservationById:(NSString *)reservationId;

/**
 @brief Generates the url that is needed to see tickets for a reservation.
 *
 @param reservationId    The id of the reservation.
 @param siteId           The site id connected to the reservation.
 @param ticketId         The ticket id.
 *
 @return url to be used for viewing tickets for a reservation with a webview.
 */
+ (NSURL *)ticketsByReservationId:(NSString *)reservationId siteId:(NSString *)siteId ticketId:(NSString *)ticketId;

/**
 @brief Generates the url that is needed to request an Alice offer.
 *
 @param reservationZuid    The id of the reservation.
 @param urlString        The base uri to the Alice offer.
 *
 @return url to be used for viewing tickets for a reservation with a webview.
 */
+ (NSURL *)aliceOfferUrlByReservationId:(NSString *)reservationZuid urlString:(NSString *)urlString;

/**
 @brief Generates the url that is needed to see FAQ.
 */
+ (NSURL *)faqUrl;

/**
 @brief Generates the url that is needed to see Terms & Conditions.
 */
+ (NSURL *)termsAndConditionsUrl;

/**
 @brief Generates the url that is needed to see Data policy.
 */
+ (NSURL *)dataPolicyUrl;



@end
