#include"head.h"
using namespace std;

void Use_object()
{
	/*
		// 创建对象
		unsigned int objectId = 0;
		// 用一个id保存它的引用
		glGenObject(1, &objectId); //生成一个对象  objectId 用来保存对象
		// 绑定对象至上下文
		glBindObject(GL_WINDOW_TARGET, objectId);
		// 设置当前绑定到 GL_WINDOW_TARGET 的对象的一些选项
		glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
		glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
		// 将上下文对象设回默认
		glBindObject(GL_WINDOW_TARGET, 0);
		*/
	return ;
}

int Create_firstWindows()
{  
	/*创建窗口的步骤
	   1-初始GLFW
	      (1)....初始化GLFW
		  (2)....设置窗口版本号、核心模式
		  (3)....创建GLFW窗口 不行就回收
		  (4)....设置GLFW窗口上下文

	   2-初始GLAD
	   (1)....加载系统OpenGL指针
	   (2)....渲染循环(Render Loop) 
	       1)....状态设置
		   2)....状态使用
		   3)....前缓冲区
		   4)....后缓冲区

	   3-回收GLFW
	*/

	/****************GLFW*****************/
	//初始化GLFW
	glfwInit();
	//设置版本我们将主版本号(Major)和次版本号(Minor)都设为3，也就是openGL3.3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//我们同样明确告诉GLFW我们使用的是核心模式(Core-profile)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建窗口
	GLFWwindow* window = glfwCreateWindow(400, 300, "FirstOpenGLWindow", NULL, NULL);
	if (window == nullptr)
	{
		cout << "Failed to Create GLFW window" << endl;
		//结束GLFW
		glfwTerminate();
		return -1;
	}

	//GLFW将窗口的上下文设置为当前线程的上下文
	glfwMakeContextCurrent(window);


	/****************GLAD*****************/
	//glad:加载系统相关的OpenGL函数指针地址
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	//渲染循环(Render Loop)
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //状态设置
		glClear(GL_COLOR_BUFFER_BIT);         //状态使用
		//glfw：交换缓冲区和轮询IO事件（按键按下、鼠标释放等）更新窗口状态，并调用对应的回调函数
		//双缓冲(Double Buffer)
		glfwSwapBuffers(window); //前缓冲区：屏幕上显示的图像 交换颜色缓冲
		glfwPollEvents();        //后缓冲区：正在渲染的图像
	}
	//glfw:回收前面分配的GLFW相关资源
	glfwTerminate();
	return 0;
}
