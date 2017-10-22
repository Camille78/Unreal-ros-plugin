// 2016 - Community based open project

#include "Unreal_ROS.h"
#include "time.h"
#include "AllowWindowsPlatformTypes.h"
#include <string>
#include <stdio.h>
#include "HideWindowsPlatformTypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "ROSSerialClientComponent.h"


// Sets default values for this component's properties
UROSSerialClientComponent::UROSSerialClientComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ros::NodeHandle nh;
	m_nh = nh;
}

UROSSerialClientComponent::~UROSSerialClientComponent()
{
	delete m_cartNavState_pub;
	delete m_transformMsg_pub;
	delete m_yawCmd_sub;
	delete m_velocityCmd_sub;
}

// Called when the game starts
void UROSSerialClientComponent::BeginPlay()
{
	Super::BeginPlay();

        m_cartNavState_pub = new ros::Publisher("/drone101/cartNavState", &m_cartNavState);
        m_transformMsg_pub = new ros::Publisher("/drone101/usvTransform", &m_transform);
        m_velocityCmd_sub = new ros::Subscriber<std_msgs::Float64, UROSSerialClientComponent>("/drone101/velocityCmd", &UROSSerialClientComponent::VelocityCmdCallback, this);
        m_yawCmd_sub = new ros::Subscriber<std_msgs::Float64, UROSSerialClientComponent>("/drone101/yawCmd", &UROSSerialClientComponent::YawCmdCallback, this);
}

void UROSSerialClientComponent::InitROS(FString _rosMaster)
{
	std::string rosMasterStr(TCHAR_TO_UTF8(*_rosMaster));
	char * rosMaster = const_cast <char *>(rosMasterStr.c_str());

	UE_LOG(LogTemp, Log, TEXT("Connecting to server at %s"), *_rosMaster);
	m_nh.initNode(rosMaster);
	m_nh.advertise(*m_transformMsg_pub);
	m_nh.advertise(*m_cartNavState_pub);
	m_nh.subscribe(*m_velocityCmd_sub);
	m_nh.subscribe(*m_yawCmd_sub);
}

void UROSSerialClientComponent::PublishCartNavStateMsg(int id, float y, float x, float z, float yaw, float speed)
{
	m_cartNavState.cart_track.header.stamp = m_nh.now();
	m_cartNavState.cart_track.header.frame_id = "/base";
	m_cartNavState.cart_track.point.x = x;
	m_cartNavState.cart_track.point.y = y;
	m_cartNavState.cart_track.point.z = z;

	m_cartNavState.trackID = id;
	m_cartNavState.cog = yaw;
	m_cartNavState.sog = speed;

	m_cartNavState_pub->publish(&m_cartNavState);
}

void UROSSerialClientComponent::PublishTransformMsg(float y, float x, float z, float roll, float pitch, float yaw) {

	m_transform.position.x = x;
	m_transform.position.y = y;
	m_transform.position.z = z;

	m_transform.orientation.x = roll;
	m_transform.orientation.y = pitch;
	m_transform.orientation.z = yaw;

	m_transformMsg_pub->publish(&m_transform);
}

void UROSSerialClientComponent::YawCmdCallback(const std_msgs::Float64 & _yawCmd)
{
	float yaw = (float)_yawCmd.data;
	OnNewYawCommand.Broadcast(yaw);
}
void UROSSerialClientComponent::VelocityCmdCallback(const std_msgs::Float64 & _velCmd)
{
	float velocity = (float)_velCmd.data;
	OnNewVelocityCommand.Broadcast(velocity);
}


// Called every frame
void UROSSerialClientComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	m_nh.spinOnce();
}

