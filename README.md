# SSImageScroller
iOS Image Scroller autoadaptive with customizable scroll indicator. It can use arrays of [UIImage imageNamed:@"nameofimage"] or NSURL array

#Installation 
1 - Download test project \n
2 - Copying SSImageSlider.h and SSImageSlider.m into your new project\n
3 - Create new UIView in your UIViewController (you can use XIB or Storyboard)\n
4 - Assign SSImageSlider as class to your new UIView\n
5 - Select "selection color" in the side tab on Xib controller\n
6 - Add the delegation method below to your UIViewController\n
7 - Attach Delegate and Datasource to your Controller\n
8 - Add <SSImageSliderDelegate, SSImageSliderDataSource> to your Controller\n
9 - Build and run\n

#SSImagePager DataSource
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

#SSImagePager Delegate
- (void) imagePager:(SSImageSlider *)imagePager didScrollToIndex:(NSUInteger)index
{
    NSLog(@"%s %lu", __PRETTY_FUNCTION__, (unsigned long)index);
}

- (void) imagePager:(SSImageSlider *)imagePager didSelectImageAtIndex:(NSUInteger)index
{
    NSLog(@"%s %lu", __PRETTY_FUNCTION__, (unsigned long)index);
}

