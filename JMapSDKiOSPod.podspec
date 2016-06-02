#
# Be sure to run `pod lib lint JMapSDKiOSPod.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'JMapSDKiOSPod'
  s.version          = '1.2.0'
  s.summary          = 'The Jibestream JMap iOS SDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'This CocoaPod provides the latest version of the Jibestream iOS SDK'

  s.homepage         = 'www.jibestream.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Jibestream' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/Jibestream/JMapSDKiOSPod.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.platform = :ios, '8.0'
  s.vendored_frameworks = 'JMap.framework'
  s.source_files = 'JMapSDKiOSPod/Classes/**/*'
 
  # s.resource_bundles = {
  #   'JMapSDKiOSPod' => ['JMapSDKiOSPod/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
