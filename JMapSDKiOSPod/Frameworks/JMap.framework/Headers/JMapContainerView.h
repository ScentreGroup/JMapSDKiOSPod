//
//  jMapContainerView.h
//  JMapSDK
//
//  Created by Sean Batson on 2015-03-27.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JMap/JMapFoundation.h>
#import "JMapDataModel.h"

@class JMapBaseElement;
@class JMapVenue;
@class JMapSVGParser;
@class JMapMapLabels;
@class JMapProximities;
@class JMapSVGStyle;
@class JMapCanvas;
@class JMapDevices;
@class JMapTextDirection;
@class JMapDestination;
@class JMapFloor;
@class JMapWaypoint;
@class JMapAmenity;
@class JMapDestination;
@class JMapBuilder;
@class JMapTextDirections;
@class JMapsUserLocationAnnotation;
@class JMapsYouAreHere;
@class JMapScriptsWebProcessor;
@class JMapCustomStyleSheet;
@class JMapSelectedLocation;
@class JMapBaseModelObject;
@class JMapAMStyles;
@class JMapZone;
@class JMapPathPerFloor;
@class JMapPointOnFloor;
@class UIKitHelperCustomThresholds;

@protocol JMapDelegate;
@protocol JMapDataSource;

/*!
 * @interface JMapContainerView
 *  This is the map container view of the SDK. This view is subviewed into a view controller for  rendering of user supplied map documents.
 */
@interface JMapContainerView : UIScrollView

#pragma mark - JMapContainerView 
#pragma mark JMapContainerView - Properties
/*!
 * A readonly context to the map's delegate instance
 */
@property (nonatomic, strong, readonly) JMapVenue *venueObject;
/*!
 * A readonly context to the map's delegate instance
 */
@property (nonatomic, strong, readonly) JMapCanvas *jMapView;
/*!
 * A readonly context to the map's delegate instance
 */
@property (unsafe_unretained, nonatomic) IBOutlet id<JMapDelegate> jMapsDelegate;
/*!
 * A readonly context to the map's datasource instance
 */
@property (unsafe_unretained, nonatomic) IBOutlet id<JMapDataSource> jMapsDataSource;
/*!
 * A readonly context to the map's way finding path data
 */
@property (strong, nonatomic, readonly) NSDictionary *mappedPathData;
/*!
 * A readonly context to the map's current floor when path finding is active
 */
@property (nonatomic, strong, readonly) JMapFloor *currentFloor;
/*!
 * A readonly context to the map's destination floor when path finding is active
 */
@property (nonatomic, strong, readonly) JMapFloor *targetFloor;
/*!
 * A readonly flag of the current label toggle state
 */
@property (nonatomic, assign, readonly) BOOL toggleMapLabels;
/*!
 * A readonly context to the map's userlocation annotation
 */
@property (nonatomic, strong, readonly) JMapsUserLocationAnnotation *userLocation;

/*!
 * YAH customizable attributes
 */
@property (nonatomic, readwrite) float userLocationScale;

/*!
 * sourceDocument - The document source to load
 * To load via http create a http NSURL object -URLWithString: were scheme is http / https
 * To load a local "svg" resource create a file NSURL object -fileURLWithPath:
 * if embedded within bundle specify filename only.
 */
@property (strong, nonatomic) NSURL *sourceDocument;
/*!
 * The You Are Here object, contains current device location, floor and heading
 */
@property (nonatomic, strong, readonly) JMapsYouAreHere *youAreHereToken;
/*!
 * Map view rotation gesture
 */
@property (strong, nonatomic, readonly) UIRotationGestureRecognizer *rotationGestureRecogniser;

/*!
 * Enable / disable label collision detection
 */
@property (nonatomic) BOOL enableLabelCollision;

/*!
 * Status Map Tiling off/on
 */
@property (nonatomic,getter=isMapTilingEnabled, readonly) bool tilingEnabled;

/*!
 * Device object of building
 */
@property (nonatomic, strong, readonly) JMapDevices *device;

/*!
 * Device Id of device
 */
@property (nonatomic, strong, readonly) NSString *deviceId;

/*!
 * Map Id of Floor/Map
 */
@property (nonatomic, strong, readonly) NSNumber *mapId;

/*!
 * Language code set for location
 */
@property (nonatomic, strong, readonly) NSString *languageCode;

/*!
 * CMS url
 */
@property (nonatomic, strong, readonly) NSString *prefixURL;

/*!
 * Size of tiling on map
 */
@property (nonatomic, strong, readonly) NSNumber *tileSize;

#pragma mark JMapContainerView - Methods

/*!
 * Deletes Local Cache
 */
+ (void)deleteCacheFolder;

/*!
 * Prints current SDK Version
 */
+ (NSString *)JMapSDKVersion;

/*!
 * Prints SDK version notes
 */
+ (NSString *)JMapSDKVersionNotes;

/*!
 * Get All Map Layers
 */
- (NSArray <NSString*>*)getMapLayers;

/*!
 * Reload all Map Data for selected location
 */
- (void)reloadMapDataForSelectedLocation:(JMapSelectedLocation *)location;

/*!
 * Hide selected map layer
 * @param mapLayer a string of a layer name to be hidden
 */
- (void)hideMapLayer:(NSString *)mapLayer;

/*!
 * Show selected map layer
 * @param mapLayer a string of a layer name to be shown
 */
- (void)showMapLayer:(NSString *)mapLayer;

/*!
 * Show only selected map layers
 * @param mapLayer a list of layer names to be shown
 */
- (void)showOnlyMapLayers:(NSArray <JMapBaseElement*>*)mapLayers;

/*!
 * Reset and make map layers visible
 */
- (void)resetMapLayers;

/*!
 * Enable map layer to be interactive
 * @param layerName a string of a layer name to enable interactivity
 */
- (void)enableLayerInteractivity:(NSString *)layerName;

/*!
 * Disable map layer interactive
 * @param layerName a string of a layer name to disable interactivity
 */
- (void)disableLayerInteractivity:(NSString *)layerName;

/*!
 * Reset map layer interactivity
 */
- (void)resetLayersInteractivity;

/*!
 * Highlight shape in specified layer
 * @param layerName a string of the layer name to highlight
 * @param idDic a NSDictionary of the data-* key-value pairing of the specified shape
 * @param style a custom JMapSVGStyle object for highlighting the unit
 */
- (void)highlightLayerWithName:(NSString *)layerName byIdPair:(NSDictionary *)idDic withSVGStyle:(JMapSVGStyle *)style;

/*!
 * Unhighlight shape in specified layer
 * @param layerName a string of the layer name to highlight
 * @param idDic a NSDictionary of the data-* key-value pairing of the specified shape
 */
- (void)unhighlightLayerWithName:(NSString *)layerName withIdPair:(NSDictionary *)idDic;

// This command is used by UIViews to tell main to tell vCommander to check if UIView's new positon causes collision with others
- (void)tellMainToTellViewCommanderIGotUpdated:(UIView *)thisView;
// Image of floor
// Obsoleted
//-(UIImage *)twoUnitsWithPaddingToImage:(int)firstUnit secondUnit:(int)secondUnit minSize:(float)minSize padding:(float)padding firstXY:(CGPoint *)firstXY secondXY:(CGPoint *)secondXY scale:(float)scale;

- (UIView *)getBlueDotView;

/*!
 * Helper method which returns UIImage for two destinations.
 * @param firstDestination JMapDestination* of first destination.
 * @param secondDestination JMapDestination* of second destination.
 * @param onFloor JMapFloor* floor containing two destinations.
 * @param minSize float minimum size of image. The retunred image will always be square.
 * @param padding float padding to be added to returned image.
 * @param scale float 2.0 for 2x Retina, 3.0 for 3x Retina...
 * @return UIImage* image for two destinations.
 */
- (UIImage *)twoDestinationsOnFloorToImage:(JMapDestination *)firstDestination secondDestination:(JMapDestination *)secondDestination onFloor:(JMapFloor *)onFloor minSize:(float)minSize padding:(float)padding scale:(float)scale;

/*!
 * Get image of Floor/Map with Rectangle parameters
 * @param mapId NSNumber* obtained from JMapFloor mapId
 * @param cropRect CGRect, the rectangle to be cropped on the map
 * @param toRect CGRect, the rectangle that contains the cropped rectangle (size adjustable)
 * @return UIImage* of cropped image
 */
- (UIImage *)cropImageOfFloor:(NSNumber *)mapId cropRect:(CGRect)cropRect toRect:(CGRect)toRect;

/*!
 * Get image of Floor/Map with Rectangle
 * @param floorIndex NSInteger, equivalent to floor sequence
 * @param withRect CGRect, the rectangle to be cropped
 * @return UIImage* of cropped rect on floor
 */
- (UIImage *)imageOfFloor:(NSInteger)floorIndex withRect:(CGRect)withRect;

/*!
 * Get view of Floor/Map by Floor Index
 * @param floorIndex NSInteger, equivalent to floor sequence
 * @return UIView* of entire floor
 */
- (UIView *)viewOfFloor:(NSInteger)floorIndex;

/*!
 * Get number of floors in floor stack/building
 * @return NSInteger value
 */
- (NSInteger)howManyFloorsInStack;

/*!
 * Get view of current Floor/Map
 * @return UIView* object
 */
- (UIView *)getCurrentFloorView;

/*!
 * Set SVG Icon highlight
 * @param thisIcon JMapSVGParser*
 */
- (void)highlightIcon:(JMapSVGParser *)thisIcon;

/*!
 * Set SVG Icon unhighlight
 * @param thisIcon JMapSVGParser*
 */
- (void)unhighlightIcon:(JMapSVGParser *)thisIcon;

// What is the default floor
/*!
 * Get initial Floor/Map Id
 * @return NSNumber* mapId
 */
- (NSNumber *)defaultFloorId;

// Get current floor
/*!
 * Get the current viewing Floor/Map
 * @return JMapFloor* object
 */
- (JMapFloor *)getCurrentFloor;

// Get floor from view
/*!
 * Get Floor/Map by View
 * @param thisView UIView*
 * @return JMapFloor* object
 */
- (JMapFloor *)getFloorForView:(UIView *)thisView;

// Get all Destinations
/*!
 * Get a list of all Destination in this building
 * @return An NSArray of JMapDestination* object(s)
 */
- (NSArray<JMapDestination*>*)getDestinations;
// Bryan: Jan 24th 2016 Obsoleting all JMapBaseElement helpers
// SDK will no longer serve Bezier Shapes to clients
// Get destination from destination ID int
//-(id)getDestinationById:(int)thisDestinationId;
// Get Destination from Unit returned by jMapViewDidTapOnUnit
//-(id)getDestinationFromUnit:(id)thisUnit;

/*!
 * Get Destination by ClientId
 * @param clientId NSString*, can be found in content manager
 * @return JMapDestination* object
 */
- (JMapDestination*)getDestinationByClientId:(NSString *)clientId;

/*!
 * Get Destination by DestinationId
 * @param destinationId NSNumber*, unique identifier of the destination
 * @return JMapDestination* object
 */
- (JMapDestination *)getDestinationByDestinationId:(NSNumber *)destinationId;

/*!
 * Get Destination(s) by Waypoint
 * @param waypoint JMapwaypoint* associated with the destination
 * @return An NSArray* of JMapDestination* object(s)
 */
- (NSArray<JMapDestination*>*)getDestinationsByWp:(JMapWaypoint*)waypoint;

/*!
 * Get Destination(s) by Floor Sequence Number
 * @param floorSequence NSNumber*
 * @return An NSArray* of JMapDestination* object(s)
 */
- (NSArray<JMapDestination*>*)getDestinationsByFloorSequence:(NSNumber *)floorSequence;

/*!
 * Get Destination(s) by Map/Floor Id
 * @param mapId NSNumber*
 * @return An NSArray* of JMapDestination* object(s)
 */
- (NSArray<JMapDestination*>*)getDestinationsByMapId:(NSNumber *)mapId;

/*!
 * Get Destination(s) by CategoryId
 * @param categoryId NSNumber* of the unique category identifier
 * @return An NSArray* of JMapDestination* object(s)
 */
- (NSArray<JMapDestination*>*)getDestinationsByCategoryId:(NSNumber *)categoryId;

/*!
 * Get a list of all Waypoints
 * @return An NSArray* of JMapWaypoint* object(s)
 */
- (NSArray<JMapWaypoint*>*)getWayspoints;

/*!
 * Get a Waypoint by WaypointId
 * @param waypointId NSNumber*, can be found in map builder
 * @return JMapWaypoint* object
 */
- (JMapWaypoint *)getWayPointById:(NSNumber *)waypointId;

/*!
 * Get an array of all the Amenities
 * @return An NSArray of JMapAmenity* object(s)
 */
- (NSArray<JMapAmenity*>*)getAmenities;

/*!
 * Get an array of all the Amenities on a particular floor
 * @return An NSArray of JMapAmenity* object(s)
 */
- (NSArray <JMapAmenity*>*)getAmenitiesOnFloor;

/*!
 * Get a list of all Waypoints that have an Amenity association
 * @return An NSArray* of JMapWaypoint* object(s)
 */
- (NSArray<JMapAmenity*>*)getAmenityWaypoints;

/*!
 * Get Amenity with AmenityId
 * @param amenityId NSNumber* found in content manager
 * @return JMapAmenity* object
 */
- (JMapAmenity*)getAmenityById:(NSNumber *)amenityId;

/*!
 * Get all data from shapes of given layer name
 * @param layerName NSString*
 * @return An NSArray* of NSDictionary object(s)
 */
- (NSArray <NSMutableDictionary*>*)getAllShapesDataFromLayerName:(NSString *)layerName;

/*!
 * Get a list of all Waypoints on this Map/Floor Id
 * @param mapId NSNumber* obtained from JMapFloor mapId
 * @return An NSArray* of JMapWaypoint* object(s)
 */
- (NSArray<JMapWaypoint*>*)getWaypointsFromMapId:(NSNumber *)mapId;

// WayFind
/*!
 * Get Path for by from and to Waypoints
 * @param fromWaypoint JMapWaypoint*, starting waypoint object
 * @param toWaypoint JMapWaypoint*, ending waypoint object
 * @param accessibility NSNumber*, 50/100 (50 - use most accessible path, 100 - use fastest path)
 * @return An NSArray* of JMapPathPerFloor object
 */
- (NSArray<JMapPathPerFloor*>*)findPathForWaypoint:(JMapWaypoint *)fromWaypoint toWaypoint:(JMapWaypoint *)toWaypoint accessibility:(NSNumber *)accessibility;
// Obsolete as of 1.0.11
// Use findPathForWaypoint:toWaypoint:accessibility:
//-(NSArray *)findWaypointsForUnit:(int)fromUnitId toUnit:(int)toUnit accessibility:(int)accessibility;

// Text Directions v2.0 Line Of Sight
// Input wayfindArray is result of findPathForWaypoint:toWaypoint:accessibility:
// Input:
// filterOn Jibestream solution or raw Text Direction for every waypoint
// addTDifEmptyMeters must be over 0 or filter disabled
// UTurnInMeters must be over 0 or filter disabled
/*!
 * Generate list of text directions
 * @param wayfindArray NSArray*, list of array of wayfind floors (returned from findPathForWaypoint method)
 * @param filterOn BOOL to toggle using filters or not for generating text directions
 * @param addTDifEmptyMeters float threshold used for combining text directions (continue past)
 * @param UTurnInMeters float threshold for initiating a u-turn
 * @param customThreshHolds UIKitHelperCustomThresholds*
 * @return An NSArray* of NSString* object(s)
 */
- (NSArray <NSArray <NSString*>*>*)makeTextDirections:(NSArray <JMapPathPerFloor*>*)wayfindArray filterOn:(BOOL)filterOn addTDifEmptyMeters:(float)addTDifEmptyMeters UTurnInMeters:(float)UTurnInMeters customThreshHolds:(UIKitHelperCustomThresholds *)customThreshHolds;
// Obsolete as of 1.0.11
// Use makeTextDirections:filterOn:addTDifEmptyMeters:UTurnInMeters:
//-(NSArray *)findTextDirectionsFromUnit:(int)fromUnitId toUnit:(int)toUnit accessibility:(int)accessibility;

// Soften path
// Prototype. Do not use until further notice
- (NSArray<JMapPathPerFloor*>*)softenPath:(NSArray<JMapPathPerFloor*>*)wayfindArray;

// getIconByWaypoint
/*!
 * Get Icon by Waypoint
 * @param waypoint JMapWaypoint*
 * @return JMapSVGParser* object
 */
- (JMapSVGParser *)getIconByWaypoint:(JMapWaypoint *)waypoint;

/*!
 * Correct blue dota XY and place it on WayFind Path
 * @param setOfPoints JMapPathPerFloor* from wayfind method call
 * @param point CGPoint of current (x,y)
 * @param noFurtherThan float in pixels
 * @return CGPoint nearest to wayfinding Path
 */
- (CGPoint)correctPointUsingWayfindPath:(JMapPathPerFloor *)setOfPoints point:(CGPoint)point noFurtherThan:(float)noFurtherThan;

/*!
 * Correct blue dot XY and place it on floor
 * @param setOfPaths NSArray* of JMapPathData object(s) on floor
 * @param allWaypoints NSArray of JMapWaypoint object(s) on floor
 * @param onFloor JMapFloor* of current viewing floor
 * @param point CGPoint of current (x,y)
 * @param noFurtherThan float in pixels
 * @return CGPoint to nearest Path
 */
- (CGPoint)correctPointUsingPaths:(NSArray<JMapPathData*>*)setOfPaths allWaypoint:(NSArray <JMapWaypoint*>*)allWaypoints onFloor:(JMapFloor *)onFloor point:(CGPoint)point noFurtherThan:(float)noFurtherThan;

/*!
 * Suggests to redraw the existing wayfind path if user exceeds a set distance threshold
 * @param setOfPoints JMapPathPerFloor from wayfind method call
 * @param point CGPoint current location (x,y)
 * @param threshold float distance to trigger rerouting
 */
- (BOOL)shouldCorrectToRerouteWayfindPath:(JMapPathPerFloor *)setOfPoints withCurrentPoint:(CGPoint)currentPoint threshold:(float)threshold;

// General
/*!
 * Get device's current visible Rectangle
 * @return CGRect unit
 */
- (CGRect)visibleRect;

/*!
 * Get size of the world in world units
 * @return CGSize unit
 */
- (CGSize)worldSize;

// World Zoom Scale
/*!
 * Get zoom scale of world units to pixels
 * @return CGFloat unit
 */
- (CGFloat)worldZoomScale;

/*!
 * Get Floor/Map one above current floor
 * @return JMapFloor* object
 */
- (JMapFloor *)floorUp;

/*!
 * Get Floor/Map one below current floor
 * @return JMapFloor* object
 */
- (JMapFloor *)floorDown;

/*!
 * Get default Floor/Map Id
 * @return NSNumber* mapId
 */
- (NSNumber *)getVenueDefaultFloorId;

// Get list of styles
/*!
 * Get a list of all styles
 * @return An NSArray of NSString* style names
 */
- (NSArray <NSString*>*)getListOfStyles;

// Get list of styles from shapes
/*!
 * Get a list of all styles from shapes
 * @return An NSArray of NSString* style names
 */
- (NSArray <NSString*>*)getListOfStylesFromShapes;

/*!
 * Catch All String
 * @param thisString NSString*
 * @param thisFloor JMapFloor*
 * @return CGRect unit
 */
- (CGRect)rectForCatchAllString:(NSString *)thisString forFloor:(JMapFloor *)thisFloor;

/*!
 * Get Rectangle of current Map's center
 * @return CGRect unit
 */
- (CGRect)rectForMapCenter;

/*!
 * Get Rectangle for style string
 * @param styleString NSString*
 * @param onFloor JMapFloor*
 * @return CGRect unit
 */
- (CGRect)rectForStyleString:(NSString *)styleString onFloor:(JMapFloor *)onFloor;

// Reset rotation
/*!
 * Reset the Floor/Map's rotation
 */
- (void)resetRotation;

/*!
 * Get a list all destination categories in this building
 * @return An NSArray* of JMapCategoryModel objects
 */
- (NSArray<JMapCategoryModel*>*)getCategories;

/*!
 * Highlight units by selected categories
 * @param thisArray NSArray* of JMapCategoryModel objects
 * @param andAnimate BOOL to set animation on/off
 * @param thisColor UIColor* to highlight unit
 */
- (void)highlightCategories:(NSArray <JMapCategoryModel *>*)thisArray andAnimate:(BOOL)andAnimate withColor:(UIColor *)thisColor;

/*!
 * Unhighlight units by select categories
 * @param thisArray NSArray* of JMapCategoryModel objects
 */
- (void)unHighlightCategories:(NSArray <JMapCategoryModel*>*)thisArray;

/*!
 * Get Destination Proximities by Destination Id
 * @param destinationIdInt NSNumber*
 * @return JMapProximities* object
 */
- (JMapProximities *)returnDestinationProximitiesForDestinationIdInt:(NSNumber *)destinationIdInt;

/*!
 * Get Map coordinates of a unit returned by jMapViewDidTapOnDestination
 * @param thisUnit JMapDestination* object
 * @return An NSArray of JMapPointOnFloor* object(s)
 */
- (NSArray<JMapPointOnFloor*>*)getXYFromUnit:(JMapDestination *)thisUnit;

/*!
 * Get Map coordinates of a unit with Floor/Map
 * @param thisUnit JMapDestination* object
 * @param onFloor JMapFloor* oject
 * @return An NSArray of JMapPointOnFloor* object(s)
 */
- (NSArray<JMapPointOnFloor*>*)getXYFromUnit:(JMapDestination *)thisUnit onFloor:(JMapFloor *)onFloor;
// setUnitHighlight
// Obsolete
// Use setDestinationHighlight:
//-(void)setUnitHighlight:(id)thisUnit withStyleArray:(NSMutableArray *)thisStyleArray;
//-(void)setUnitHighlight:(id)thisUnit withStyle:(JMapSVGStyle *)thisStyle;
//-(void)setUnitHighlight:(id)thisUnit withColor:(UIColor *)thisColor;

/*!
 * Get Destination highlight status
 * @param thisDestination JMapDestination*
 * @return BOOL for highlight on/off
 */
- (BOOL)getDestinationHighlightStatus:(JMapDestination *)thisDestination;

/*!
 * Set Destination highlight with style array
 * @param destination JMapDestination* to be highlighted
 * @param thisStyleArray NSMutableArray*, list of JMapSVGStyle* objects
 */
- (void)setDestinationHighlight:(JMapDestination *)destination withStyleArray:(NSMutableArray *)thisStyleArray;

/*!
 * Set Destination highlight with style
 * @param destination JMapDestination* to be highlighted
 * @param thisStyle JMapSVGStyle* with specified style
 */
- (void)setDestinationHighlight:(JMapDestination *)destination withStyle:(JMapSVGStyle *)thisStyle;

/*!
 * Set Destination highlight with color
 * @param destination JMapDestination* to be highlighted
 * @param thisColor UIColor* with specified color
 */
- (void)setDestinationHighlight:(JMapDestination *)destination withColor:(UIColor *)thisColor;

/*!
 * Unhighlight Destination unit
 * @param destination JMapDestination* to be unhighlighted
 */
- (void)setDestinationUnHighlight:(JMapDestination *)destination;

/*!
 * Get animation status of Destination
 * @param destination JMapDestination*
 * @return BOOL for animation on/off
 */
- (BOOL)isDestinationAnimated:(JMapDestination *)destination;

// Set unit animation
/*!
 * Set Destination unit animation
 * @param destination JMapDestination* to animate
 * @param doAnimate BOOL, add animation to the destination
 */
- (void)setDestinationAnimation:(JMapDestination *)destination doAnimate:(BOOL)doAnimate;

// Obsolete Feb 22
// Get Category from Unit returned by jMapViewDidTapOnUnit
//-(id)getCategoryFromUnit:(id)thisUnit;
/*!
 * Zoom in on a unit on current Floor/Map
 * @param thisUnit JMapDestination* to zoom to
 * @param onFloor JMapFloor* object of the unit
 * @param withPadding CGSize of the area included in the zoom
 * @param doAnimate BOOL, add animation to the unit
 */
- (void)zoomUnit:(JMapDestination *)thisUnit onFloor:(JMapFloor *)onFloor withPadding:(CGSize)withPadding doAnimate:(BOOL)doAnimate;

/*!
 * Unhighlight all units
 */
- (void)unhighlightAllUnits;

/*!
 * Expose map rotation to handle tooltip, popup card, SVG icon rotations
 */
- (void)iRotatedMap;

/*!
 * Add a popup card to map with View at coordinate on Floor/Map
 * @param thisView UIView* of the popup card
 * @param atXY CGPoint, placement in x,y coordinates of the popup card
 * @param frozenFrame BOOL to have popup card scale with zoom or not
 * @param toFloor JMapFloor* object to place the popup card
 */
- (void)addPopupCardToMap:(UIView *)thisView atXY:(CGPoint)atXY frozenFrame:(BOOL)frozenFrame toFloor:(JMapFloor *)toFloor;

// Change freeze attrib of a popup card in map
/*!
 * Change freeze attribute of a popup card in map
 * @param thisView UIView* of the popup card
 * @param newFreezeFrame BOOL to have popup card scale with zoom or not
 */
- (void)setFreezeFramePopupCardForView:(UIView *)thisView newFreezeFrame:(BOOL)newFreezeFrame;

// Remove a popup card in map
/*!
 * Remove a popup card to map
 * @param thisView UIView*
 */
- (void)removePopupCardToMap:(UIView *)thisView;

/*!
 * Hide all Icons other than given type(s)
 * @param thisTypeArray NSArray*
 */
- (void)showOnlyIconsTypeArray:(NSArray <NSString*>*)thisTypeArray;

/*!
 * Show all Icons of given type
 * @param thisType NSString*
 */
- (void)showOnlyIconsType:(NSString *)thisType;

/*!
 * Show all Icons
 */
- (void)showAllIcons;

/*!
 * Hide all Icons
 */
- (void)hideAllIcons;

/*!
 * Animate all Icons with scale
 * @param scale NSNumber*, the scale factor for animation
 */
-(void)animateAllIcons:(NSNumber *)scale;

/*!
 * Un-animate all Icons
 */
-(void)unAnimateAllIcons;

// Styling of Icons
/*!
 * Highlight all Icons
 */
-(void)highlightAllIcons;

/*!
 * Unhighlight all icons with scale
 */
-(void)unHighlightAllIcons;

/*
 * Highlight all vacant units
 * @param color UIColor* to higlight the vacant units in
 */
-(void)highlightVacantUnitsWithColor:(UIColor *)color;

/*!
 * Remove all effects on Icons, they are displayed, not animated or highlights
 */
-(void)resetAllIcons;

/*!
 * Apply default style to all AM Icons
 * @param bg UIColor* background color
 * @param mg UIColor* middleground color
 * @param fg UIColor* foreground color
 */
-(void)applyDefaultWithColorsToAll:(UIColor *)bg mg:(UIColor *)mg fg:(UIColor *)fg;

/*!
 * Apply highlight style to all AM Icons
 * @param bg UIColor* background color
 * @param mg UIColor* middleground color
 * @param fg UIColor* foreground color
 */
-(void)applyHighlightWithColorsToAll:(UIColor *)bg mg:(UIColor *)mg fg:(UIColor *)fg;

/*!
 * Apply custom styling to Amenity Icon at Waypoint
 * @param amenity JMapAmenity* object
 * @param waypoint JMapWaypoint* associated to the amenity
 * @param bg UIColor* background color
 * @param mg UIColor* middleground color
 * @param fg UIColor* foreground color
 */
-(void)applyHighlightWithColorsToAmenity:(JMapAmenity *)amenity waypoint:(JMapWaypoint *)waypoint bg:(UIColor *)bg mg:(UIColor *)mg fg:(UIColor *)fg;

/*!
 * Unhighlight Amenity Icon at Waypoint
 * @param amenity JMapAmenity* object
 * @param waypoint JMapWaypoint* selected
 */
// Unhighlight Amenity
-(void)applyUnHighlightToAmenity:(JMapAmenity *)amenity waypoint:(JMapWaypoint *)waypoint;

// Apply highlight colours for currently tapped Amenity/Mover

/*!
 * Set all AM Icons to default style
 */
- (void)setIconsToDefaultStyle;

/*!
 * Set all Am Icons to highlighted style
 */
- (void)setIconsToHighlightedStyle;

/*!
 * Reset any transformation applied to on Floor/Map
 * @param thisView UIView*
 */
- (void)resetTransformOfFloor:(UIView *)thisView;

/*!
 * Get floor view with floor sequence
 * @param thisSequence NSNumber* from JMapFloor sequence
 * @return UIView* object
 */
- (UIView *)floorViewFromSequence:(NSNumber *)thisSequence;

/*!
 * Reload unit labels for all floors
 */
- (void)reloadUnitLabels;

/*!
 * Remove unit labels for all floors
 */
- (void)removeUnitLabels;

/*!
 * Reload unit labels on one floor
 * @param forFloorId UIView*
 */
- (void)reloadUnitLabelsForFloorView:(UIView *)forFloorId;

/*!
 * Remove unit labels on one floor
 * @param forFloorId UIView*
 */
- (void)removeUnitLabelsForFloorView:(UIView *)forFloorId;

/*!
 * Generate default wayfind view
 */
- (void)defaultWayFindView:(NSArray<JMapPathPerFloor*>*)pathPerFloor;

/*!
 * Remove all WayFind related views for all floors
 */
- (void)removeAllWayFindViews;

/*!
 * Add WayFind related view on one floor
 * @param thisView UIView* of the wayfind path view
 * @param atXY CGPoint coordinate to place the view
 * @param forFloorId UIView* obtained from floorViewFromSequence helper method
 */
-(void)addWayFindView:(UIView *)thisView atXY:(CGPoint)atXY forFloorId:(UIView *)forFloorId;

/*!
 * Remove WayFind related view on one floor
 * @param thisView UIView* of the wayfind path view
 * @param forFloorId UIView* obtained from floorViewFromSequence helper method
 */
-(void)removeWayFindView:(UIView *)thisView forFloorId:(UIView *)forFloorId;

/*!
 * Place YouAreHere view at coordinates
 * @param point CGPoint of where to place the view on the map
 * @param thisView UIImageView* to be placed
 */
-(UIImageView *)placePersonInView:(CGPoint)point thisView:(UIImageView *)thisView;

/*!
 * Remove YouAreHere view
 * @param thisView UIView*, previously created placePersonInView view
 */
-(void)removePersonInView:(UIView *)thisView;

/*!
 * Get Id of current Floor/Map
 * @param NSNumber* mapId, matches JMapFloor mapId
 */
-(NSNumber *)currentMapId;

/*!
 * Reload all Amenities and Movers
 */
-(void)reloadAmenitiesAndMovers;

/*!
 * Get Zone for ClientId
 * @param clientId NSString*, clientId generated in content manager
 */
-(JMapZone *)getZoneByClientId:(NSString *)clientId;

/*!
 * Get Zone for ZoneId
 * @param zoneId NSNumber*, unique zone identifier
 */
-(JMapZone *)getZoneByZoneId:(NSNumber *)zoneId;

/*!
 * Get Waypoints By Zone
 * @param zone JMapZone* object
 * @return list of waypoints associated with the zone
 */
- (NSArray <JMapWaypoint*>*)getWaypointsByZone:(JMapZone *)zone;

// Get Destinations By Zone
/*!
 * Get Destinations By Zone
 * @param zone JMapZone* object
 * @return list of destinations associated with the zone
 */
- (NSArray <JMapDestination*>*)getDestinationsByZone:(JMapZone *)zone;

/*!
 * Load remote map resource language code.
 * @param code The language code for localized content
 * @param delegate Delegate proocol reference is required.
 * @param datasource Datasource proocol reference is required.
 * @return JMapContainer view.
 */
- (instancetype)initDataWithLanguage:(NSString *)code
                         andDelegate:(id<JMapDelegate>)delegate
                       andDataSource:(id<JMapDataSource>)datasource;

/*!
 * Load remote map resource language code.
 * @param code The language code for localized content
 * @param tilingEnabled switch on/off map tiling when it is not needed due to small maps
 * @param delegate Delegate proocol reference is required.
 * @param datasource Datasource proocol reference is required.
 * @return JMapContainer view.
 */
- (instancetype)initDataWithLanguage:(NSString *)code
                         andDelegate:(id<JMapDelegate>)delegate
                       andDataSource:(id<JMapDataSource>)datasource
                 andMapTilingEnabled:(BOOL)tilingEnabled;
/*!
 * Load remote map resource language code.
 * @param code The language code for localized content
 * @param tilingEnabled switch on/off map tiling when it is not needed due to small maps
 * @param delegate Delegate proocol reference is required.
 * @param datasource Datasource proocol reference is required.
 * @param size override the default map tiling size only if map tiling is enabled
 * @return JMapContainer view.
 */
- (instancetype)initDataWithLanguage:(NSString *)code
                         andDelegate:(id<JMapDelegate>)delegate
                       andDataSource:(id<JMapDataSource>)datasource
                 andMapTilingEnabled:(BOOL)tilingEnabled
                      andMapTileSize:(CGFloat)size;

/*!
 * Loads an embedded map document
 * @param fileName The local or remote map resource to load
 * @param inBundle True for Embedded and false remote resource
 */
- (void)setFileName:(NSURL *)fileName isInBundle:(BOOL) inBundle;

/*!
 * Reverse Lookup by destination object
 * @param destinationId The id which represents a unit, room or store entity on a map
 * @return Waypoints
 */
- (JMapWaypoint *)getWayPointByDestinationId:(NSNumber *)destinationId;

/*!
 * Fetch the closest waypoint to any given point on the map
 * @param pointOnMap The point to which to query map for the closest way point
 * @return Waypoints
 */
- (JMapWaypoint *)getNearestWayPointForLocationOnMap:(JMAPPoint)pointOnMap;

/*!
 * Updates the "You are here" point on a given Map.
 * @param position A JMAPPoint used to positon the YAH object
 * @param orientation The heading in degrees of the YAH object. Default is 0
 * @param confidence float value measured in pixels
 * @return JMapsYouAreHere
 */
-(JMapsYouAreHere *)updateCurrentLocationWithCurrentPosition:(JMAPPoint)position
                          orientation:(NSInteger)orientation
                            confidence:(float)confidence;


/*!
 * Hide method for YAH icon
 */
-(void)hideYAH;

/*!
 * Show method for YAH icon
 */
-(void)showYAH;

/*!
 * Get the available building locations
 */
- (void)getVenueLocations;
/*!
 * Get the available building locations
 * @param lcode The language code for map content
 * @param dataSource The JMapDataSource reference for the protocol call backs
 * @param option This enables / disables Map Tiling
 * @return JMapContainerView The map instance for implementation. The JMapDelegate property can be set to this instance prior to be being subviewed
 */
+ (JMapContainerView*)getVenueLocationsForLanguage:(NSString *)lcode withDataSource:(id<JMapDataSource>)dataSource andMapTilingEnabled:(BOOL)option;

/*!
 * Focuses the map to center the "You are here" icon
 */
- (void)focusToYah;

/*!
 * NSArray of the floors(instances of JMapFloor) of the building.
 * @return Array of JMapFloor object(s)
 */
- (NSArray <JMapFloor*>*)getLevels;

/*!
 * Switches the currently viewed level to the one specified by "floorId"
 * @param floorId The new floor to switch the current map to
 * @return The success or failure of request
 */
- (BOOL)setLevelById:(NSNumber *)floorId;

/*!
 * Switches the currently viewed level to the one specified by sequence number
 * @param floorSequence The new floor to switch the current map to
 * @return The success or failure of request
 */
- (BOOL)setLevelBySequence:(NSNumber *)floorSequence;

/*!
 * The floor instance (of JMapFloor) that corresponds to the specified floorId
 * @param floorId The JMapFloor object to fetch
 * @return JMapFloor* object
 */
- (JMapFloor *)getLevelById:(NSInteger)floorId;

/*!
 * The floor instance (of JMapFloor) that corresponds to the specified sequence
 * @param floorSequence The new floor to switch the current map to
 * @return JMapFloor* object
 */
- (JMapFloor *)getLevelBySequence:(NSInteger)floorSequence;

/*!
 * Highlights the specified destinationId
 * @param destinationId The unit, store or room to highlight on map
 * @param rgb comma seperated values: 255,255,255
 */
- (void)highlightDestination:(NSString*)destinationId andRgbVal:(NSString *)rgb;

/*!
 * Highlights the specified units by category
 * @param categoryId The group of units, stores or rooms to highlight on map
 * @param rgb comma seperated values: 255,255,255
 */
- (void)highlightStoresByCategory:(NSString *)categoryId andRgbVal:(NSString *)rgb;

/*! 
 * Reset the highlight
 */
- (void)resetHighlight;

/*!
 * Scales and positions the map to it's default state
 */
- (void)resetMapPosition;

/*! 
 * Clears the generated waypoint path
 */
- (void)clearWayPoints;

/*! 
 * Clears the visible labels
 */
- (void)clearAllLabels;
/*! 
 * Clears the visible Legends/Icons
 */
- (void)clearAllLegends;
/*! 
 * Clears the map of any drawn paths or highlights and resets the map's scale and position to default
 */
- (void)clearMapAndReset;

/*!
 * NSArray of all the destination ids on that floor.
 * @return NSArray
 */
-(NSArray<JMapDestination*>*)getDestinationsOnFloor;

/*!
 * The width of the map. Can be used, along with height, to convert Geo-coords to x,y
 * @return CGFloat width of map
 */
- (float)getMapWidth;

/*!
 * The height of the map. Can be used, along with height, to convert Geo-coords to x,y
 * @return CGFloat height of map
 */
- (float)getMapHeight;

/*!
 * Get the floor sequence
 * @return OPEN_MAX on failure or floor level on success
*/
- (NSInteger)getSequence;

/*!
 * Reload street names for all Floors/Maps
 */
- (void)reloadStreetNames;

/*!
 * Remove street names for all Floors/Maps
 */
- (void)removeStreetNames;

#pragma mark JMapContainerView - Deprecated Methods

/*!
 * Use jMapViewShouldDisplayAsTooltipDestinations: instead. This parameter will be deprecated and no longer available in version 2.0.0.
 */
@property (nonatomic, readonly) JMapToggleLabelType labelType __attribute__((deprecated("Use jMapViewShouldDisplayAsTooltipDestinations: instead")));

/*!
 * Use jMapViewShouldDisplayAsTooltipDestinations: instead. This parameter will be deprecated and no longer available in version 2.0.0.
 */
@property (nonatomic) JMapToolTipStyle toolipEdgeStyle __attribute__((deprecated("Use jMapViewShouldDisplayAsTooltipDestinations: instead")));

/*!
 * initDataWithDeviceId: will be deprecated and no longer available in version 2.0.0"
 */
- (instancetype)initDataWithDeviceId:(NSString *)device
                            language:(NSString *)code
                               mapId:(NSNumber *)mapid
                             mapName:(NSURL *)filename
                         andDelegate:(id<JMapDelegate>)delegate __attribute__((deprecated("initDataWithDeviceId: will be deprecated and no longer available in version 2.0.0")));


/*!
 * initDataWithDeviceId: will be deprecated and no longer available in version 2.0.0
 */
- (instancetype)initDataWithDeviceId:(NSString *)device
                            language:(NSString *)code
                               mapId:(NSNumber *)mapid
                             mapName:(NSURL *)filename
                         andDelegate:(id<JMapDelegate>)delegate
                       andDataSource:(id<JMapDataSource>)datasource __attribute__((deprecated("initDataWithDeviceId: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use getLevels instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSArray<JMapFloor*>*)getMaps __attribute__((deprecated("Use getLevels instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use getCategories instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSArray <JMapCategoryModel*>*)getListOfCategories __attribute__((deprecated("Use getCategories instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * addPopupCardToMap:atXY:frozenFrame:withUnit: will be deprecated and no longer available in version 2.0.0
 */
-(void)addPopupCardToMap:(UIView *)thisView atXY:(CGPoint)atXY frozenFrame:(BOOL)frozenFrame withUnit:(id)thisUnit __attribute__((deprecated("addPopupCardToMap:atXY:frozenFrame:withUnit: will be deprecated and no longer available in version 2.0.0")));
 
/*!
 * setFreezeFramePopupCardForView:newFreezeFrame:withUnit: will be deprecated and no longer available in version 2.0.0
 */
-(void)setFreezeFramePopupCardForView:(UIView *)thisView newFreezeFrame:(BOOL)newFreezeFrame withUnit:(id)thisUnit __attribute__((deprecated("setFreezeFramePopupCardForView:newFreezeFrame:withUnit: will be deprecated and no longer available in version 2.0.0")));

/*!
 * locateLabelByDestinationId: will be deprecated and no longer available in version 2.0.0"
 */
- (void)locateLabelByDestinationId:(NSArray*)jMapDestinationArray __attribute__((deprecated("locateLabelByDestinationId: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use highlightIcon: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)hilightIcon:(JMapSVGParser *)thisIcon __attribute__((deprecated("Use highlightIcon: instead")));

/*!
 * Use unhighlightIcon: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)unhilightIcon:(JMapSVGParser *)thisIcon __attribute__((deprecated("Use unhighlightIcon: instead")));

/*!
 * getAllShapesFromDestinationId: will be deprecated and no longer available in version 2.0.0
 */
- (NSArray<JMapBaseElement*>*)getAllShapesFromDestinationId:(NSNumber *)destinationId  __attribute__((deprecated("getAllShapesFromDestinationId: will be deprecated and no longer available in version 2.0.0")));

/*!
 * rectForArrayOfStyleString: will be deprecated and no longer available in version 2.0.0
 */
- (CGRect)rectForArrayOfStyleString:(NSArray *)arrayStyleString onFloor:(JMapFloor *)onFloor __attribute__((deprecated("rectForArrayOfStyleString: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use getWaypointsByZone: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSArray *)getWaypointsByZoneId:(JMapZone *)zone __attribute__((deprecated("Use getWaypointsByZone: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use getDestinationsByZone: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSArray *)getDestinationsByZoneId:(JMapZone *)zone __attribute__((deprecated("Use getDestinationsByZone: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use reloadMapDataForSelectedLocation: by passing a JMapSelectedLocation reference. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)reloadMapData __attribute__((deprecated("Use reloadMapDataForSelectedLocation: by passing a JMapSelectedLocation reference. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * showtooltipWithName: will be deprecated and no longer available in version 2.0.0
 */
- (void)showtooltipWithName:(NSString *)name forWayPointID:(NSNumber*)wpid __attribute__((deprecated("showtooltipWithName: will be deprecated and no longer available in version 2.0.0")));
/*!
 * hidetooltipWithName: will be deprecated and no longer available in version 2.0.0
 */
- (void)hidetooltipWithName:(NSString *)name forWayPointID:(NSNumber*)wpid __attribute__((deprecated("hidetooltipWithName: will be deprecated and no longer available in version 2.0.0")));

/*!
 * insertPin: will be deprecated and no longer available in version 2.0.0
 */
- (void)insertPin:(NSString *)name atWayPointID:(NSNumber*)wpid customUIImage:(UIImage *)image  __attribute__((deprecated("insertPin: will be deprecated and no longer available in version 2.0.0")));
/*!
 * removePin: will be deprecated and no longer available in version 2.0.0
 */
- (void)removePin:(NSString *)name __attribute__((deprecated("removePin: will be deprecated and no longer available in version 2.0.0")));

/*!
 * getJibestreamStore: will be deprecated and no longer available in version 2.0.0
 */
- (JMapDestination* )getJibestreamStore:(NSString *)storeId __attribute__((deprecated("getJibestreamStore: will be deprecated and no longer available in version 2.0.0")));

/*!
 * routeToStore: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToStore:(JMapDestination *)clientId __attribute__((deprecated("routeToStore: will be deprecated and no longer available in version 2.0.0")));
/*!
 * routeToStore:withMovers: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToStore:(JMapDestination *)clientId withMovers:(BOOL)option __attribute__((deprecated("routeToStore:withMovers: will be deprecated and no longer available in version 2.0.0")));

/*!
 * routeToDestination: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToDestination:(JMapDestination *) destinationId __attribute__((deprecated("routeToDestination: will be deprecated and no longer available in version 2.0.0")));
/*!
 * routeToDestination:withMovers: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToDestination:(JMapDestination *)destinationId withMovers:(BOOL)option __attribute__((deprecated("routeToDestination:withMovers: will be deprecated and no longer available in version 2.0.0")));

/*!
 * routeToWaypoint: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToWaypoint:(JMapWaypoint *) waypointId __attribute__((deprecated("routeToWaypoint: will be deprecated and no longer available in version 2.0.0")));

/*!
 * routeToWaypoint:withMovers: will be deprecated and no longer available in version 2.0.0
 */
- (void)routeToWaypoint:(JMapWaypoint *)waypointId withMovers:(BOOL)option __attribute__((deprecated("routeToWaypoint:withMovers: will be deprecated and no longer available in version 2.0.0")));

/*!
 * getTextDirectionsByStoreId: will be deprecated and no longer available in version 2.0.0
 */
- (JMapTextDirections *)getTextDirectionsByStoreId:(JMapDestination *)destination __attribute__((deprecated("getTextDirectionsByStoreId: will be deprecated and no longer available in version 2.0.0")));

/*!
 * showTextDirectionItems: will be deprecated and no longer available in version 2.0.0
 */
- (void)showTextDirectionItems:(NSArray *)arrayOfDirectionItems __attribute__((deprecated("showTextDirectionItems: will be deprecated and no longer available in version 2.0.0")));

/*!
 * getDirectionsById: will be deprecated and no longer available in version 2.0.0
 */
- (NSArray *)getDirectionsById:(JMapDestination *)destination __attribute__((deprecated("getDirectionsById: will be deprecated and no longer available in version 2.0.0")));

/*!
 * getDirectionsById: will be deprecated and no longer available in version 2.0.0
 */
- (NSArray *)getDirectionsById:(JMapDestination *)destination withMovers:(BOOL)option __attribute__((deprecated("getDirectionsById: will be deprecated and no longer available in version 2.0.0")));

/*!
 * focusToHighlightedDestinationsAnimated: will be deprecated and no longer available in version 2.0.0
 */
- (void)focusToHighlightedDestinationsAnimated:(BOOL)animated __attribute__((deprecated("focusToHighlightedDestinationsAnimated: will be deprecated and no longer available in version 2.0.0")));

/*!
 * highlightServiceIcons: will be deprecated and no longer available in version 2.0.0
 */
- (void)highlightServiceIcons:(JMapBaseModelObject *)componentType __attribute__((deprecated("highlightServiceIcons: will be deprecated and no longer available in version 2.0.0")));

/*!
 * toggleMapLabels: will be deprecated and no longer available in version 2.0.0
 */
- (void)toggleMapLabels:(BOOL)hideShowLabels __attribute__((deprecated("toggleMapLabels: will be deprecated and no longer available in version 2.0.0")));
/*!
 * Use jMapViewShouldDisplayAsTooltipDestinations: instead. This method will be deprecated and no longer available in version 2.0.0"
 */
- (void)toggleMapLabels:(BOOL)hideShowLabels withType:(JMapToggleLabelType)type __attribute__((deprecated("Use jMapViewShouldDisplayAsTooltipDestinations: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * prepareMoverItemsWithAmenitiesFilter: will be deprecated and no longer available in version 2.0.0
 */
- (void)prepareMoverItemsWithAmenitiesFilter:(JMapAmenity *)amenityObjectFilter __attribute__((deprecated("prepareMoverItemsWithAmenitiesFilter: will be deprecated and no longer available in version 2.0.0")));

/*!
 * performSearch: will be deprecated and no longer available in version 2.0.0"
 */
- (NSArray <JMapDestination*>*)performSearch:(NSString *)searchText __attribute__((deprecated("performSearch: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use jMapViewShouldDisplayAsTooltipDestinations: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (JMapToggleLabelType)jMapViewLabelToggleDefaultType __attribute__((deprecated("Use jMapViewShouldDisplayAsTooltipDestinations: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use jMapViewWillLoadCustomCSSDictionaryHandler: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSDictionary *)jMapViewWillLoadCustomCSSDictionaryHandler:(JMapContainerView *)sender __attribute__((deprecated("Use jMapViewWillLoadCustomCSSDictionaryHandler: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * jMapViewRoutePathWayColor will be deprecated and no longer available in version 2.0.0
 */
- (UIColor *)jMapViewRoutePathWayColor __attribute__((deprecated("jMapViewRoutePathWayColor will be deprecated and no longer available in version 2.0.0")));
/*!
 * jMapViewRoutePathWayColorAttributes: will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewRoutePathWayColorAttributes:(void(^)(UIColor *pathStrokeColor, CGFloat pathStrokeWidth, UIColor *segmentStrokeColor, CGFloat segmentStrokeWidth, CGFloat pathStrokeOpacity, CGFloat segmentStrokeOpacity))attributes __attribute__((deprecated("jMapViewRoutePathWayColorAttributes: will be deprecated and no longer available in version 2.0.0")));
/*!
 * Use jMapViewRoutePathWayColorAttributes: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (UIColor *)jMapViewUnitShadowColor __attribute__((deprecated("Use jMapViewRoutePathWayColorAttributes: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * jMapViewShouldShowLabelForDestinationTouch: will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewShouldShowLabelForDestinationTouch:(JMapContainerView *)sender __attribute__((deprecated("jMapViewShouldShowLabelForDestinationTouch: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use maximumZoomScale of UIScrollView instead. Default minimumZoomScale - 0.3, maximumZoomScale - 10.. This method will be deprecated and no longer available in version 2.0.0
 */
- (CGFloat)jMapViewMaximumZoomLevel __attribute__((deprecated("Use maximumZoomScale of UIScrollView instead. Default minimumZoomScale - 0.3, maximumZoomScale - 10.. This method will be deprecated and no longer available in version 2.0.0")));

@end

#pragma mark - JMapDelegate
@protocol JMapDelegate <NSObject>

#pragma mark JMapDelegate - Methods
@optional

/*!
 * Handles and returns JMapDestination objects on destination that was tapped
 * @param thisDestinationArray NSArray*
 * @param destinationCenterPoint JMapPointOnFloor*
 */
- (void)client:(JMapContainerView *)client didTapOnDestination:(NSArray <JMapDestination *>*)thisDestinationArray destinationCenterPoint:(JMapPointOnFloor *)destinationCenterPoint;

/*!
 * Handles and returns information on destination that was tapped
 * @param dataDictionary NSDictionary of all data associated with the selected layer
 * @param layerName NSString of the layer name tapped
 */
- (void)client:(JMapContainerView *)client didTapOnCustomLayer:(NSDictionary *)dataDictionary withLayerName:(NSString *)layerName;

/*!
 * Returns XY coordinates on canvas when tapped
 * @param atXY NSValue*
 */
- (void)client:(JMapContainerView *)client didTapAtXY:(NSValue *)xy;

/*!
 * Set whether street names should be processed
 * @param thisFloor JMapFloor*
 * @return BOOL yes/no
 */
- (BOOL)client:(JMapContainerView *)client shouldProcessStreetNamesOnFloor:(JMapFloor *)thisFloor;

/*!
 * Listener for when street name process starts
 * @param thisFloor JMapFloor*
 */
- (void)client:(JMapContainerView *)client didStartProcessingStreetNameOnFloor:(JMapFloor *)thisFloor;

/*!
 * Listener for when street name process finishes
 * @param thisFloor JMapFloor* object to load street labels
 */
- (void)client:(JMapContainerView *)client didFinishProcessingStreetNameOnFloor:(JMapFloor *)thisFloor;

/*!
 * Get street name on Floor/Map
 * @param thisLabel JMapMapLabels*
 * @param thisFloor JMapFloor*
 * @return UIView* of street name label
 */
- (UIView *)client:(JMapContainerView *)client shouldDisplayStreetName:(JMapMapLabels *)label onFloor:(JMapFloor *)floor;

/*!
 * Set whether unit labels should be processed
 * @param onFloor JMapFloor* object to load labels
 */
- (BOOL)client:(JMapContainerView *)client shouldProcessUnitLabelsOnFloor:(JMapFloor *)thisFloor;

/*!
 * Listener for when unit label process starts
 * @param onFloor JMapFloor* object
 */
- (void)client:(JMapContainerView *)client didStartProcessingUnitLabelsOnFloor:(JMapFloor *)floor;

/*!
 * Listener for when process unit label finishes
 * @param onFloor JMapFloor* object
 */
- (void)client:(JMapContainerView *)client didFinishProcessingUnitLabelsOnFloor:(JMapFloor *)floor;

/*!
 * Set whether default unit labels should show trailing ellipses for text wider than label
 * Default is set to NO / false
 */
- (BOOL)client:(JMapContainerView *)client shouldShowTrailingEllipsesForDefaultUnitLabelsOnFloor:(JMapFloor *)floor;

/*!
 * Display unit label for specific destination(s)
 * @param destinations NSArray* of JMapDestination * objects
 * @param onFloor JMapFloor* object to load labels
 * @return BOOL yes/no to be displayed or not
 */
- (BOOL)client:(JMapContainerView *)client shouldDisplayUnitLabelsForDestinationsOnFloor:(NSArray <JMapDestination*>*)destinations onFloor:(JMapFloor*)floor;

/*!
 * Set whether to display destinations as tooltips or in-unit label
 * @param destinations NSArray*, list of destinations associated with the unit
 * @param onFloor JMapFloor* object associated to the unit
 * @return UIView* of unit label passed back to be rendered
 */
- (UIView *)client:(JMapContainerView *)client shouldDisplayAsToolTipDestinations:(NSArray <JMapDestination*>*)destinations onFloor:(JMapFloor *)floor;

/*!
 * Set whether to display unit label inside the unit
 * @param insideUnit BOOL* yes/no to have the view displayed inside the unit (usually YES for tooltip, NO for in-line labels)
 */
- (BOOL)client:(JMapContainerView *)client shouldDisplayLabelInsideUnitOnFloor:(JMapFloor *)floor;

/*!
 * Set whether to show LBoxes on unit or not
 * @returns BOOL yes/no to show/hide LBoxes in unit
 */
- (BOOL)client:(JMapContainerView *)client shouldShowLBoxesOnFloor:(JMapFloor *)floor;

/*!
 * Set whether to flip in-unit labels or not
 * @returns BOOL yes/no to have unit labels flip with rotation angle
 */
- (BOOL)client:(JMapContainerView *)client shouldRotateUnitLabelsOnFloor:(JMapFloor *)floor;

/*!
 *  Get content scale factor on Floor/Map
 * @param newScale NSNumber*, updated scale factor/zoom scale
 * @param onFloor JMapFloor* object
 */
- (void)client:(JMapContainerView *)client contentScaledTo:(NSNumber *)scale onFloor:(JMapFloor *)floor;

/*!
 *  Listener for when content scale factor on Floor/Map changes
 * @param nextScale NSNumber*, updated scale factor/zoom scale
 * @param onFloor JMapFloor*
 */
- (void)client:(JMapContainerView *)client scaleFactorDidChange:(NSNumber *)scale onFloor:(JMapFloor *)floor;

/*!
 * Set whether the map should load custom css
 * @return BOOL yes/no to look for custom css config file for loading custom styling
 */
- (BOOL)client:(JMapContainerView *)client shouldLoadCustomCSSDictionaryHandlerOnFloor:(JMapFloor *)onFloor;

/*!
 *  Set whether to process Amenity Icons and Movers
 * @return BOOL yes/no for loading/displaying amenity icons
 */
- (BOOL)client:(JMapContainerView *)client shouldProcessAmenityIconsOnFloor:(JMapFloor *)floor;

/*!
 *  Set styling for Amenity Icon
 * @param thisIcon JMapAmenity* object to be styled
 * @return JMapAMStyles* object containing defined styling by the user
 */
- (JMapAMStyles *)client:(JMapContainerView *)client setStyleForAmenityIcon:(JMapAmenity *)amenityIcon;

/*!
 *  Listener for when process Amenity Icons starts
 */
- (void)client:(JMapContainerView *)client didStartProcessingAmenityIconsOnFloor:(JMapFloor *)onfloor;

/*!
 *  Listener for when process Amenity Icons finishes
 */
- (void)client:(JMapContainerView *)client didFinishProcessingAmenityIconsOnFloor:(JMapFloor *)onfloor;

// Amenity/Mover icon tapped
/*!
 *  Handle tapping on Amenity Icon
 * @param thisAMIcon JMapSVGParser* object containing a .amenity property
 * @param atXY NSValue* that can be converted to CGPoint for x,y coordinates
 */
- (void)client:(JMapContainerView *)client didTapAmenityIcon:(JMapSVGParser *)amenityIcon atCoords:(NSValue *)XY;

/*!
 * Map starting to load URL data
 * @param sender mapId
 */
- (void)client:(JMapContainerView *)client willStartLoadingMapWithId:(NSNumber *)mapId;

/*!
 * Map did load URL data
 * @param sender mapId
 */
- (void)client:(JMapContainerView *)client didFinishLoadingMapWithId:(NSNumber *)mapId;

/*!
 * JMapDelegate error report method
 * @param sender The sending map container object
 * @param error The error state of request
 */
- (void)client:(JMapContainerView *)client delegateDidFailWithError:(NSString *)error;

/*!
 * Provide a custom css dictionary via a block completion call back
 * @param sender The sending map container object
 * @param completion The completion handler for this method
 */
- (void)client:(JMapContainerView *)client willLoadCustomCSSDictionaryHandlerWithCompletion:(void(^)(JMapCustomStyleSheet*))completion;

/*!
 * The touchInfo dictionary can be populated with of any the given objects noted above
 * Keys:
 *   kJMAPDataUnits
 *   kJMAPMapLegends
 *   kJMAPMapTouchPoint
 *   kJMAPDataLboxes
 *   kJMAPWayPointUnits
 *   kJMAPWayPointLboxes
 *   kJMAPMoverData
 * @param sender The sending map container object
 * @param touchInfo A NSDictionary object consisting of elements related to the map touch event
 */
- (void)client:(JMapContainerView *)client didSendTouchInfo:(NSDictionary *)touchInfo;

#pragma mark JMapDelegate - Deprecated Methods

/*!
 * Use JMapContainerView reloadStreetNames instead. This will be deprecated and no longer available in version 2.0.0
 */
- (void)reloadStreetNames __attribute__((deprecated("Use JMapContainerView reloadStreetNames instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use JMapContainerView removeStreetNames instead. This will be deprecated and no longer available in version 2.0.0
 */
- (void)removeStreetNames __attribute__((deprecated("Use JMapContainerView removeStreetNames instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didTapOnDestination:destinationCenterPoint: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)jMapViewDidTapOnDestination:(NSArray <JMapDestination *>*)thisDestinationArray destinationCenterPoint:(JMapPointOnFloor *)destinationCenterPoint __attribute__((deprecated("Use client:didTapOnDestination:destinationCenterPoint: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didTapOnCustomLayer:withLayerName: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewDidTapOnCustomLayer:(NSDictionary *)dataDictionary withLayerName:(NSString *)layerName __attribute__((deprecated("Use client:didTapOnCustomLayer:withLayerName: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didTapAtXY: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapTapAtXY:(NSValue *)atXY __attribute__((deprecated("Use client:didTapAtXY: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldProcessStreetNames: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewShouldProcessStreetNames:(JMapFloor *)thisFloor __attribute__((deprecated("Use client:shouldProcessStreetNames: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didStartProcessingStreetName: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewProcessStreetNamesStart:(JMapFloor *)thisFloor __attribute__((deprecated("Use client:didStartProcessingStreetName: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didFinishProcessingStreetName: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewProcessStreetNamesFinish:(JMapFloor *)thisFloor __attribute__((deprecated("Use client:didFinishProcessingStreetName: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldDisplayStreetName:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (UIView *)jMapViewShouldDisplayStreetName:(JMapMapLabels *)thisLabel onfloor:(JMapFloor *)thisFloor __attribute__((deprecated("Use client:shouldDisplayStreetName:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldProcessUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewShouldProcessUnitLabels:(JMapFloor *)onFloor __attribute__((deprecated("Use client:shouldProcessUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didStartProcessingUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewProcessUnitLabelsStart:(JMapFloor *)onFloor __attribute__((deprecated("Use client:didStartProcessingUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didFinishProcessingUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewProcessUnitLabelsFinish:(JMapFloor *)onFloor __attribute__((deprecated("Use client:didFinishProcessingUnitLabels: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldShowTrailingEllipsesForDefaultUnitLabelsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewDefaultUnitLabelsShouldShowTrailingEllipses __attribute__((deprecated("Use client:shouldShowTrailingEllipsesForDefaultUnitLabelsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldDisplayUnitLabelsForDestinationsOnFloor:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewShouldDisplayUnitLabelForDestinations:(NSArray<JMapDestination*>*)destinations onFloor:(JMapFloor *)onFloor __attribute__((deprecated("Use client:shouldDisplayUnitLabelsForDestinationsOnFloor:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldDisplayAsToolTipDestinations:onFloor: and client:shouldDisplayLabelInsideUnitOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (UIView *)jMapViewShouldDisplayAsTooltipDestinations:(NSArray<JMapDestination*>*)destinations onFloor:(JMapFloor *)onFloor insideUnit:(BOOL *)insideUnit __attribute__((deprecated("Use client:shouldDisplayAsToolTipDestinations:onFloor: and client:shouldDisplayLabelInsideUnitOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldShowLBoxesOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(BOOL)jMapViewShouldShowLBoxes __attribute__((deprecated("Use client:shouldShowLBoxesOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldRotateUnitLabelsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(BOOL)jMapViewShouldRotateUnitLabels  __attribute__((deprecated("Use client:shouldRotateUnitLabelsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:contentScaledTo:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)jMapViewContentScaleFactor:(NSNumber *)newScale onFloor:(JMapFloor *)onFloor __attribute__((deprecated("Use client:contentScaledTo:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:scaleFactorDidChange:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)jMapViewContentScaleFactorChange:(NSNumber *)nextScale onFloor:(JMapFloor *)onFloor __attribute__((deprecated("Use client:scaleFactorDidChange:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use jMapViewContentScaleFactorChange:onFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)jMapViewProcessAMIconsStart __attribute__((deprecated("Use client:didStartProcessingAmenityIconsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:shouldLoadCustomCSSDictionaryHandlerOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (BOOL)jMapViewShouldLoadCustomCSSDictionaryHandler __attribute__((deprecated("Use client:shouldLoadCustomCSSDictionaryHandlerOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 *  Use client:shouldProcessAmenityIconsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(BOOL)jMapViewShouldProcessAMIcons __attribute__((deprecated("Use client:shouldProcessAmenityIconsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 *  Use client:setStyleForAmenityIcon:instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(JMapAMStyles *)jMapViewThisAMIconStyle:(JMapAmenity *)thisIcon __attribute__((deprecated("Use client:setStyleForAmenityIcon: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 *  Use client:didFinishProcessingAmenityIconsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)jMapViewProcessAMIconsFinish __attribute__((deprecated("Use client:didFinishProcessingAmenityIconsOnFloor: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 *  Use client:didTapAmenityIcon:atCoords: instead. This method will be deprecated and no longer available in version 2.0.0
 */
-(void)AMIconTapped:(JMapSVGParser *)thisAMIcon atXY:(NSValue *)atXY __attribute__((deprecated("Use client:didTapAmenityIcon:atCoords: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:willStartLoadingMapWithId: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewWillStartLoading:(NSNumber *)sender __attribute__((deprecated("Use client:willStartLoadingMapWithId: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:willStartLoadingMapWithId: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewDidFinishLoading:(NSNumber *)sender __attribute__((deprecated("Use client:didFinishLoadingMapWithId: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * jMapViewWillDraw: will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewWillDraw:(JMapContainerView *)sender __attribute__((deprecated("jMapViewWillDraw: will be deprecated and no longer available in version 2.0.0")));

/*!
 * jMapViewDidDraw: will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewDidDraw:(JMapContainerView *)sender __attribute__((deprecated("jMapViewDidDraw: will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:delegateDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapView:(JMapCanvas *)sender didFailLoadWithError:(NSError *)error __attribute__((deprecated("Use client:delegateDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:delegateDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapErrorReport:(NSString *)errorReport __attribute__((deprecated("Use client:delegateDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:willLoadCustomCSSDictionaryHandlerWithCompletion: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewWillLoadCustomCSSDictionaryHandler:(JMapContainerView *)sender withCompletion:(void(^)(JMapCustomStyleSheet*))completion __attribute__((deprecated("Use client:willLoadCustomCSSDictionaryHandlerWithCompletion: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didSendTouchInfo: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapView:(JMapContainerView *)sender didSendTouchInfo:(NSDictionary *)touchInfo __attribute__((deprecated("Use client:didSendTouchInfo: instead. This method will be deprecated and no longer available in version 2.0.0")));

@end

#pragma mark - JMapDataSource
@protocol JMapDataSource <NSObject>

@required
/*!
 * Provide Authentication Credentials
 * @return @{kJMapAuthenticationTokensUser: @"", kJMapAuthenticationTokensPassword : @"", kJMapAuthenticationTokensAPIKey : @""}
 */
- (NSDictionary *)setAuthenticationTokensForClient:(JMapContainerView *)client;

/*!
 * Provide a custom SDK server end point at runtime
 * @param sender The sending map container reference
 * @return The server end point for your environment
 */
- (NSString *)setAPIRequestURLForClient:(JMapContainerView *)client;

#pragma mark - create alternative delegate methods for methods below
// NOTE: separate error response delegates from successfully returned methods
/*!
 * Map data is now available
 * @param sender The sending map container reference
 * @param data NSArray of a JMapVenu Object containing all available map data
 * @param error Non-nil in the event of a request failure
 */
- (void)client:(JMapContainerView *)client dataReadyWithVenueData:(JMapVenue *)data;

@optional

/*!
 * Locations Data Ready
 * @param sender The sending map container reference
 * @param data NSArray of JMapLocations Objects
 * @param error Non-nil in the event of a request failure
 */
- (void)client:(JMapContainerView *)client didSendAllLocationsAvailable:(NSArray <JMapLocations*>*)data;

/*!
 * JMapDataSource error report method
 * @param sender The sending map container object
 * @param error The error state of request
 */
- (void)client:(JMapContainerView *)client dataSourceDidFailWithError:(NSString *)error;


#pragma mark JMapDataSource - Deprecated Methods

/*!
 * Use setAuthenticationTokensForClient: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSDictionary *)JMapAuthenticationTokens __attribute__((deprecated("Use setAuthenticationTokensForClient: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use setAPIRequestURLForClient: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (NSString *)JMapAPIRequestURL:(JMapContainerView *)sender __attribute__((deprecated("Use setAPIRequestURLForClient: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:dataReadyWithVenueData: and client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapViewDataReady:(JMapContainerView *)sender withVenuData:(JMapVenue *)data didFailLoadWithError:(NSError *)error  __attribute__((deprecated("Use client:dataReadyWithVenueData: and client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapView:(JMapContainerView *)sender didSendAllCategoriesAvailable:(NSArray *)data didFailLoadWithError:(NSError *)error __attribute__((deprecated("Use client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapView:(JMapContainerView *)sender didSendAllDeviceRefreshDataAvailable:(NSArray *)data didFailLoadWithError:(NSError *)error __attribute__((deprecated("Use client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

/*!
 * Use client:didSendAllLocationsAvailable: and client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0
 */
- (void)jMapView:(JMapContainerView *)sender didSendAllLocationsAvailable:(NSArray <JMapLocations*>*)data didFailLoadWithError:(NSError *)error __attribute__((deprecated("Use client:didSendAllLocationsAvailable: and client:dataSourceDidFailWithError: instead. This method will be deprecated and no longer available in version 2.0.0")));

@end

/*!
 *  This allows for the clearing of map SDK cached data
 */
@interface JMapCacheManagement : NSObject

/*!
 * Clear all cached data before or after initializing of JMapContainerView
 * @param modelData The completion handler on the success or failure
 * @param svgData The completion handler on the success or failure
 */
- (void)clear:(void(^)(NSError *mdlError))modelData svgData:(void(^)(NSError *svgError))svgData;

@end




