//
//  ZDKLockVendor.h
//  ZDK
//
//  Created by Kevin Henriksson on 2022-07-04.
//  Copyright © 2022 Zaplox AB. All rights reserved.
//

#ifndef ZDKLockVendor_h
#define ZDKLockVendor_h

/**
 *  Enumeration to describe lock vendors supported in the ZDK.
 */
typedef NS_ENUM(NSInteger, ZDKLockVendor) {
    /**
     * @brief Key is supplied by Assa Abloy
     */
    ZDKLockVendorAssaAbloy,
    
    /**
     * @brief Key is supplied by Dorma Kaba
     */
    ZDKLockVendorDormaKaba,
    
    /**
     * @brief Key is supplied by Salto
     */
    ZDKLockVendorSalto,
    
    /**
     * @brief Key is supplied by Zaplox
     */
    ZDKLockVendorZaplox,
    
    /**
     * @brief Key vendor is not supported
     */
    ZDKLockVendorUnsupported
};


#endif /* ZDKLockVendor_h */
