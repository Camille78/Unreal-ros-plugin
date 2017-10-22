// 2016 - Community based open project

#pragma once
#include <ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>
#include <custom_msgs/stampedCartesianTrack.h>
#include "Components/ActorComponent.h"
#include "ROSSerialClientComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewYawCmdDelegate,float, Yaw);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewVelocityCmdDelegate,float, Velocity);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_ROS_API UROSSerialClientComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UROSSerialClientComponent();
	~UROSSerialClientComponent();

	ros::NodeHandle m_nh;
	custom_msgs::stampedCartesianTrack m_cartNavState; //Example of use with custom msg
	geometry_msgs::Pose m_transform;		   //Example of use with standard ros msg

	ros::Publisher *m_transformMsg_pub;
	ros::Publisher *m_cartNavState_pub;
	ros::Subscriber<std_msgs::Float64, UROSSerialClientComponent> *m_velocityCmd_sub;
	ros::Subscriber<std_msgs::Float64, UROSSerialClientComponent> *m_yawCmd_sub;

	UPROPERTY(BlueprintAssignable, Category = "Rosserial")
		FOnNewYawCmdDelegate OnNewYawCommand;

	UPROPERTY(BlueprintAssignable, Category = "Rosserial")
		FOnNewVelocityCmdDelegate OnNewVelocityCommand;

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Rosserial")
		FString shipID;

	// Warning : x and y axis are inverted between ROS and UE ==> Ros' x-axis = Unreal's y-axis
	UFUNCTION(BlueprintCallable, Category = "Rosserial")
		void PublishTransformMsg(float y, float x, float z, float roll, float pitch, float yaw);

	UFUNCTION(BlueprintCallable, Category = "Rosserial")
		void PublishCartNavStateMsg(int id, float y, float x, float z, float yaw, float speed);

	UFUNCTION(BlueprintCallable, Category = "Rosserial")
		void InitROS(FString _rosMaster);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void VelocityCmdCallback(const std_msgs::Float64 & _velCmd);
	void YawCmdCallback(const std_msgs::Float64 & _yawCmd);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
