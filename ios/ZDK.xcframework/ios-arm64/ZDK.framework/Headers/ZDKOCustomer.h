//
//  ZDKOCustomer.h
//  ZDK
//
//  Created by Kevin Henriksson on 2021-10-30.
//  Copyright © 2021 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOSite.h"
#import "ZDKOCustomerDetails.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Representation of a Customer in the Zaplox system.
 */
@protocol ZDKCustomer
/** @name Properties */

/**
 @brief Sites of the customer.

 @return NSArray<ZDKOSite>
 */
@property (nonatomic, readonly) NSArray<ZDKOSite *> *sites;

/**
 @brief Details of the customer such as assets info.

 @return ZDKOCustomerDetails
 */
@property (nonatomic, readonly) ZDKOCustomerDetails *details;

@end


/**
 @brief Representation of a Customer in the Zaplox system.
 */
@interface ZDKOCustomer : ZDKObject <ZDKCustomer>

+ (void)getCustomerWithCachePolicy:(ZDKCachePolicy)cachePolicy completion:(ZDKOCustomerResponseBlock)completeBlock;

@end

NS_ASSUME_NONNULL_END
