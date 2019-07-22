//
//  ViewController.m
//  MacroGather
//
//  Created by Teonardo on 2019/7/22.
//  Copyright © 2019 Teonardo. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor orangeColor];
    
    NSLog(@"%@", NSStringFromCGRect(self.view.frame));
    NSLog(@"screen_width %f", SCREEN_WIDTH);
    NSLog(@"screen_height %f", SCREEN_HEIGHT);
    
    [self addLabel];
}

- (void)addLabel {
    UILabel *label = [[UILabel alloc] init];
    [self.view addSubview:label];
    label.frame = CGRectMake(0, STATUS_BAR_SAFE_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT - STATUS_BAR_SAFE_HEIGHT - SAFE_AREA_BOTTOM_INSET);
    UIFont *font = AdaptedFont(30);
    NSLog(@"font %@", font);
    label.font = font;
    label.textAlignment = NSTextAlignmentCenter;
    label.textColor = ColorWithHex(000000);
    label.text = @"Safe Area";
    label.backgroundColor = [UIColor cyanColor];
}


@end
