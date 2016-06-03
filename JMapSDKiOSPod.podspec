Pod::Spec.new do |s|
s.name             = 'JMapSDKiOSPod'
s.version          = '1.2.0'
s.summary          = 'The Jibestream JMap iOS SDK.'

s.description      = 'This CocoaPod provides the latest version of the Jibestream iOS SDK'

s.homepage         = 'http://www.jibestream.com/'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'Jibestream' => 'lyuen@jibestream.com' }
s.source           = { :git => 'https://github.com/Jibestream/JMapSDKiOSPod.git', :tag => "#{s.version}" }

s.ios.deployment_target = '8.0'
s.platform = :ios, '8.0'
s.source_files = 'JMapSDKiOSPod/Classes/*.{h,m}'
s.public_header_files = 'JMapSDKiOSPod/Classes/*.h'
s.vendored_frameworks = 'JMapSDKiOSPod/Frameworks/JMap.framework'
end