//
//  ZDKOCustomerDetails.h
//  ZDK
//
//  Created by Kevin Henriksson on 2021-10-30.
//  Copyright © 2021 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOCustomerAssetsInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKOCustomerDetails : ZDKObject

/**
 @brief Premium app image resources for customer.

 @return ZDKOCustomerAssetsInfo
 */
@property (nullable, nonatomic, readonly) ZDKOCustomerAssetsInfo *assetsResourceInfo;

@end

NS_ASSUME_NONNULL_END
