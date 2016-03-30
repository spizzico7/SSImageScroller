//
//  ViewController.m
//  SSImageSlider
//
//  Created by Simone Spizzichino on 30/03/16.
//  Copyright © 2016 simonespizzichino. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - SSImagePager DataSource
- (NSArray *) arrayWithImages:(SSImageSlider*)pager
{
    return @[
             [UIImage imageNamed:@"testimage"],
             [NSURL URLWithString:@"https://ilbuongiorno.it/immagini-articoli/1278/french-bulldog-puppies-new-york-french-bulldog-black--24836-wallpaper-wallemon-pictures_e1460.jpg"],
             [UIImage imageNamed:@"testimage"]
             ];
}

- (UIViewContentMode) contentModeForImage:(NSUInteger)image inPager:(SSImageSlider *)pager
{
    return UIViewContentModeScaleAspectFill;
}

- (NSString *) captionForImageAtIndex:(NSUInteger)index inPager:(SSImageSlider *)pager
{
    return @[
             @"Test 1",
             @"Test 2",
             @"Test 3"
             ][index];
}

#pragma mark - SSImagePager Delegate
- (void) imagePager:(SSImageSlider *)imagePager didScrollToIndex:(NSUInteger)index
{
    NSLog(@"%s %lu", __PRETTY_FUNCTION__, (unsigned long)index);
}

- (void) imagePager:(SSImageSlider *)imagePager didSelectImageAtIndex:(NSUInteger)index
{
    NSLog(@"%s %lu", __PRETTY_FUNCTION__, (unsigned long)index);
}


@end
