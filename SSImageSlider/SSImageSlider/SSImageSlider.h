//
//  SSImageSlider.h
//  SSImageSlider
//
//  Created by Simone Spizzichino on 26.03.16.
//  Copyright (c) 2016 Simone Spizzichino. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef void(^SSImageSliderImageRequestBlock)(UIImage*image, NSError * error);

@class SSImageSlider;

#pragma mark  - Data source
@protocol SSImageSliderDataSource <NSObject>

@required
- (NSArray *) arrayWithImages:(SSImageSlider*)pager;
- (UIViewContentMode) contentModeForImage:(NSUInteger)image inPager:(SSImageSlider*)pager;

@optional
- (UIImage *) placeHolderImageForImagePager:(SSImageSlider*)pager;
- (NSString *) captionForImageAtIndex:(NSUInteger)index  inPager:(SSImageSlider*)pager;
- (UIViewContentMode) contentModeForPlaceHolder:(SSImageSlider*)pager;

@end

#pragma mark  - Delegate
@protocol SSImageSliderDelegate <NSObject>

@optional
- (void) imagePager:(SSImageSlider *)imagePager didScrollToIndex:(NSUInteger)index;
- (void) imagePager:(SSImageSlider *)imagePager didSelectImageAtIndex:(NSUInteger)index;

@end

#pragma mark  - Image source

@protocol SSImageSliderImageSource <NSObject>

-(void) imageWithUrl:(NSURL*)url completion:(SSImageSliderImageRequestBlock)completion;

@end


@interface SSImageSlider : UIView{
    UIView *selectionIndicator;
    float _selectionIndicatorWidth;
    float _selectionIndicatorPositionY;
    float _selectionIndicatorPositionX;
}

// Delegate and Datasource
@property (weak) IBOutlet id <SSImageSliderDataSource> dataSource;
@property (weak) IBOutlet id <SSImageSliderDelegate> delegate;
@property (weak) IBOutlet id <SSImageSliderImageSource> imageSource;

@property (nonatomic) IBInspectable UIColor *selectionColor;


// General
@property (nonatomic) UIViewContentMode contentMode;
@property (nonatomic) UIScrollView *scrollView;
@property (nonatomic) UIPageControl *pageControl;
@property (nonatomic) NSUInteger currentPage;
@property (nonatomic) BOOL indicatorDisabled;
@property (nonatomic) BOOL bounces;
@property (nonatomic) BOOL imageCounterDisabled;
@property (nonatomic) BOOL hidePageControlForSinglePages; // Defaults YES

// Slideshow
@property (nonatomic) NSUInteger slideshowTimeInterval; // Defaults 0.0f (off)
@property (nonatomic) BOOL slideshowShouldCallScrollToDelegate; // Defaults YES

// Caption Label
@property (nonatomic, strong) UIColor *captionTextColor; // Defaults Black
@property (nonatomic, strong) UIColor *captionBackgroundColor; // Defaults White (with an alpha of .7f)
@property (nonatomic, strong) UIFont *captionFont; // Defaults to Helvetica 12.0f points

- (void) reloadData;
- (void) setCurrentPage:(NSUInteger)currentPage animated:(BOOL)animated;

@end
