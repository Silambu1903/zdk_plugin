#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint digitalkey.podspec` to validate before publishing.
#

Pod::Spec.new do |s|
  s.name             = 'digitalkey'
  s.version          = '0.0.1'
  s.summary          = 'A new Flutter project.'
  s.description      = <<-DESC
A new Flutter project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.dependency 'ZDK', '~> 1.0.5'
  s.static_framework =true
  s.platform = :ios, '13.6'
  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-framework ZDK','DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end
