//
//  ViewController.m
//  Calculator
//
//  Created by Jorge Valbuena on 2014-04-16.
//  Copyright (c) 2014 Jorge Valbuena. All rights reserved.
//

#import "ViewController.h"

// private properties
@interface ViewController ()

@property (nonatomic) BOOL userIsInTheMiddleOfEntereingANumber;

@end

@implementation ViewController

@synthesize Dot;
@synthesize Screen;
@synthesize Method;
@synthesize userIsInTheMiddleOfEntereingANumber = _userIsInTheMiddleOfEntereingANumber;

NSString *myDot = @".";
float result;
float screenF;

- (NSNumber *)screenValue {
    NSNumberFormatter *f = [[NSNumberFormatter alloc] init];
    [f setNumberStyle:NSNumberFormatterDecimalStyle];
    return [f numberFromString:self.Screen.text];
}

-(IBAction)Number1:(UIButton *)sender{
    [self appendDigit:@"1"];
}


-(IBAction)Number2:(UIButton *)sender{
    [self appendDigit:@"2"];
}


-(IBAction)Number3:(UIButton *)sender{
    [self appendDigit:@"3"];
}


-(IBAction)Number4:(UIButton *)sender{
    [self appendDigit:@"4"];
}


-(IBAction)Number5:(UIButton *)sender{
    [self appendDigit:@"5"];
}


-(IBAction)Number6:(UIButton *)sender{
    [self appendDigit:@"6"];
}


-(IBAction)Number7:(UIButton *)sender{
    [self appendDigit:@"7"];
}


-(IBAction)Number8:(UIButton *)sender{
    [self appendDigit:@"8"];
}


-(IBAction)Number9:(UIButton *)sender{
    [self appendDigit:@"9"];
}


-(IBAction)Number0:(UIButton *)sender{
    [self appendDigit:@"0"];
}


- (IBAction)Dot:(UIButton *)sender {
    
    NSString *currentText = Screen.text;
    if ([currentText rangeOfString:@"." options:NSBackwardsSearch].length == 0) {
        [self appendDigit:@"."];
    }
}


- (void)appendDigit:(NSString *)digit {
    
    if ([self.Screen.text isEqualToString:@"0"] && ![digit isEqualToString:@"."]) {
        self.Screen.text = digit;
    } else if(self.userIsInTheMiddleOfEntereingANumber){
        self.Screen.text = digit;
        self.userIsInTheMiddleOfEntereingANumber = NO;
    } else{
        self.Screen.text = [Screen.text stringByAppendingString:digit];
    }
    
}


-(IBAction)Times:(UIButton *)sender{
    
    //if(!self.userIsInTheMiddleOfEntereingANumber) [self Equals];
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 1;
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
}


-(IBAction)Divide:(UIButton *)sender{
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 2;
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
}


-(IBAction)Substract:(UIButton *)sender{
    
    /*
    if(self.userIsInTheMiddleOfEntereingANumber){
        //[self MyOperations];
        [self Equals];
    }
     */
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 3;
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
}


-(IBAction)Plus:(UIButton *)sender{
    
    /*
    if(self.userIsInTheMiddleOfEntereingANumber){
        screenF = [[self screenValue] floatValue];
        [self MyOperations];
        [self Equals];
    }
     */
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 4;
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
}


- (IBAction)Percent:(UIButton *)sender {
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 5;
    
    [self MyOperations];
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
    
    Screen.text = [NSString stringWithFormat:@"%.2f", result];
}


- (IBAction)PositiveOrNegative:(UIButton *)sender {
    
    screenF = [[self screenValue] floatValue];
    
    self.Method = 6;
    
    [self MyOperations];
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
    
    Screen.text = [NSString stringWithFormat:@"%.2f", result];
}


-(IBAction)Equals:(UIButton *)sender{
    
    [self MyOperations];
    
    self.Screen.text = [NSString stringWithFormat:@"%.2f", result];
    
    self.Method = 0;
    
    self.userIsInTheMiddleOfEntereingANumber = NO;
    
}


-(IBAction)AllClear:(UIButton *)sender{
    
    Method = 0;

    result = 0;
    
    self.userIsInTheMiddleOfEntereingANumber = NO;
    
    Screen.text = [NSString stringWithFormat:@"0"];
    
}


 - (double) MyOperations{
    
     float runningF = [[self screenValue] floatValue];
     result = 0;
     
     if(screenF == 0){
         result = screenF;
     } else {
         switch (self.Method) {
             case 1:
                 result = screenF * runningF;
                 break;
             case 2:
                 result = (runningF == 0.0)? 0.0 : screenF / runningF;
                 break;
             case 3:
                 result = screenF - runningF;
                 break;
             case 4:
                 result = screenF + runningF;
                 break;
             case 5:
                 result = screenF / 100;
                 break;
             case 6:
                 if(!screenF == 0 && screenF > 0){
                     result = - screenF;
                 } else{
                     result = + screenF;
                 }
                 break;
             default:
                 break;
         }
     }
     
     return result;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end