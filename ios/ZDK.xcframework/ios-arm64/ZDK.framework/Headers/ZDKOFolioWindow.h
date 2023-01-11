//
//  ZDKOFolioWindow.h
//  ZDK
//
//  Created by David Aberg on 2017-08-02.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOFolioItem.h"
#import "ZDKOTaxItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A Folio Window is representing a tab, or a account in the folio.
 */
@protocol ZDKFolioWindow

/** @name Properties */

/**
 @brief The window number.
 */
- (nonnull NSNumber *)windowNumber;

/**
 @brief The list of folio items.
 */
- (nullable NSArray<ZDKOFolioItem *> *)folioItems;

/**
 @brief The list of tax items.
 */
- (nullable NSArray <ZDKOTaxItem *> *)taxItems;

@end

/**
 @brief Representation of the Zaplox Folio Window Object.
 */
@interface ZDKOFolioWindow : ZDKObject <ZDKFolioWindow>

@property (nonatomic, readonly) NSNumber *origWindowNumber;
@property (nonatomic, readonly) NSArray /*ZDKOFolioItem*/ *origFolioItems;
@property (nonatomic, readonly) NSArray /*ZDKOTaxItem*/ *origTaxItems;

@end

NS_ASSUME_NONNULL_END
