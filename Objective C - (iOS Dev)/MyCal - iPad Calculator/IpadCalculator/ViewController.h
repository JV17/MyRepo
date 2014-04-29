//
//  ViewController.h
//  IpadCalculator
//
//  Created by Jorge Valbuena on 2014-04-29.
//  Copyright (c) 2014 Jorge Valbuena. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property(strong,nonatomic) IBOutlet UILabel *Screen;
@property(assign,nonatomic) NSInteger Method;
@property (weak, nonatomic) IBOutlet UIButton *Dot;

-(IBAction)Number1:(UIButton *)sender;
-(IBAction)Number2:(UIButton *)sender;
-(IBAction)Number3:(UIButton *)sender;
-(IBAction)Number4:(UIButton *)sender;
-(IBAction)Number5:(UIButton *)sender;
-(IBAction)Number6:(UIButton *)sender;
-(IBAction)Number7:(UIButton *)sender;
-(IBAction)Number8:(UIButton *)sender;
-(IBAction)Number9:(UIButton *)sender;
-(IBAction)Number0:(UIButton *)sender;
-(IBAction)Times:(UIButton *)sender;
-(IBAction)Divide:(UIButton *)sender;
-(IBAction)Substract:(UIButton *)sender;
-(IBAction)Percent:(UIButton *)sender;
-(IBAction)Dot:(UIButton *)sender;
-(IBAction)PositiveOrNegative:(UIButton *)sender;
-(IBAction)Equals:(UIButton *)sender;
-(IBAction)Plus:(UIButton *)sender;
-(IBAction)AllClear:(UIButton *)sender;
-(double)MyOperations;
- (void)appendDigit:(NSString *)digit;


@end
