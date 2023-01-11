#import "DigitalkeyPlugin.h"
#if __has_include(<digitalkey/digitalkey-Swift.h>)
#import <digitalkey/digitalkey-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "digitalkey-Swift.h"
#endif

@implementation DigitalkeyPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftDigitalkeyPlugin registerWithRegistrar:registrar];
}
@end
