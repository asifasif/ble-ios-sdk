//
//  Beacon.h
//  Bluetooth
//
//  Created by Callum Henshall on 03/03/15.
//  Copyright (c) 2015 Sidereo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreLocation/CoreLocation.h>


/**
 * Represents a Bluetooth Beacon or an iBeacon.
 */
@interface Beacon : NSObject <NSCoding>

/**
 *
 */
@property (assign, nonatomic, readonly) BOOL iBeacon;

@property (strong, nonatomic, readonly) NSString *name;
@property (strong, nonatomic, readonly) NSUUID *uuid;

/**
 *
 */
@property (assign, nonatomic, readonly) CLBeaconMajorValue majorValue;
/**
 *
 */
@property (assign, nonatomic, readonly) CLBeaconMinorValue minorValue;

/**
 * Creates a normal Bluetooth Beacon.
 */
- (instancetype)initWithName:(NSString *)name
                        uuid:(NSUUID *)uuid;

/**
 * Creates an iBeacon.
 */
- (instancetype)initWithName:(NSString *)name
                        uuid:(NSUUID *)uuid
                       major:(CLBeaconMajorValue)major
                       minor:(CLBeaconMinorValue)minor;

/**
 *
 */
- (CLBeaconRegion *)beaconRegion;

- (BOOL)isEqual:(id)object;

/**
 * Compares the received to a given object.
 * @return YES if all the properties of both objects are equal.
 */
- (BOOL)isEqualToBeacon:(Beacon *)beacon;

@end

@interface CLBeacon (Beacon)

/**
 * Returns a Beacon representing an iBeacon.
 */
- (Beacon *)beacon;

@end