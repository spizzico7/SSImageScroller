//
//  ViewController.h
//  SSImageSlider
//
//  Created by Simone Spizzichino on 30/03/16.
//  Copyright © 2016 simonespizzichino. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SSImageSlider.h"

@interface ViewController : UIViewController <SSImageSliderDelegate, SSImageSliderDataSource>{
    IBOutlet SSImageSlider *_imagePager;
}


@end

