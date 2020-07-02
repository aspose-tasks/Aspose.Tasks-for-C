# Aspose.Tasks for C++

[Aspose.Tasks for C++](https://products.aspose.com/Tasks/cpp) library allows the developers to add Tasks generation & recognition capabilities to their own C++ applciations.

Aspose.Tasks for C++ offers Project management APIs that enable C++ applications to not only read and manipulate Microsoft Project® documents but also write Microsoft Project® documents in both MPP and XML formats - all without using Microsoft Project®.

<p align="center">
<a title="Download complete Aspose.Tasks for C++ source code" href="https://github.com/aspose-Tasks/Aspose.Tasks-for-C/archive/master.zip">
	<img src="https://raw.github.com/AsposeExamples/java-examples-dashboard/master/images/downloadZip-Button-Large.png" />
  </a>
</p>

This repository contains [Examples](Examples) for Aspose.Tasks for C++ to help you learn and write your own applications.

Directory | Description
--------- | -----------
[Examples](Examples)  | A collection of C++ examples that help you learn the product features


# C++ API to Process Project Files

A standalone C++ library that enables the C++ developers to [generate, update, render, & convert project files](https://products.aspose.com/tasks/cpp) from within C++ projects without Microsoft Project®.

## Project File Processing Features

- [Create an empty project file](https://docs.aspose.com/display/taskscpp/Creating+and+Saving) and save it as XML, to stream or to Microsoft MPP file.
- Supports [encoding of the `MPX` files](https://docs.aspose.com/display/taskscpp/Reading+Project#ReadingProject-WorkingWithEncodings).
- [Read and write default properties of projects](https://docs.aspose.com/display/taskscpp/Default+Project+Properties) to speed up the project setup.
- [Set the project calculation mode](https://docs.aspose.com/display/taskscpp/Project+Calculation+Modes) to be manual, automatic or none.
- Read and write [project calendar properties](https://docs.aspose.com/display/taskscpp/Calendar+Properties), such as, fiscal year and weekday properties.
- Read and write [project currency properties](https://docs.aspose.com/display/taskscpp/Currency+Properties).
- [Perform project rescheduling](https://docs.aspose.com/display/taskscpp/Project+Rescheduling) from start, finish date or reschedule only the incomplete tasks.
- Offers various [project utility features](https://docs.aspose.com/display/taskscpp/Utility+Features), such as, calculate critical path, read filter data, extract embedded objects etc.
- Use Task, Resource and Project fields as a [formula in expressions](https://docs.aspose.com/display/taskscpp/Formula+Expressions).
- Identify [Cross Project Tasks](https://docs.aspose.com/display/taskscpp/Identify+Cross+Project+Tasks), get [predecessor tasks](https://docs.aspose.com/display/taskscpp/Predecessor+and+Successor+Tasks) and [cross project predecessor](https://docs.aspose.com/display/taskscpp/Cross+Project+Predecessors) tasks.
- Supports working with [task links](https://docs.aspose.com/display/taskscpp/Creating+Task+Links), [baselines](https://docs.aspose.com/display/taskscpp/Working+with+Baselines), [project resources](https://docs.aspose.com/display/taskscpp/Working+with+Resources), and [VBA](https://docs.aspose.com/display/taskscpp/Working+with+VBA).
- [Convert project data](https://docs.aspose.com/display/taskscpp/Converting+Project+Data) to other [supported file formats](https://docs.aspose.com/display/taskscpp/Supported+File+Formats).
- So many more [features](https://docs.aspose.com/display/taskscpp/Developer+Guide).

## Read & Write Project Files

**Microsoft Project®:** MPP, MPT, MPX, XML

## Save Project Data As

**Primavera:** P6 XML, PM XER\
**Microsoft Excel®:** XLSX\
**Fixed Layout:** PDF\
**Images:** JPEG, PNG, TIF, SVG\
**Text:** TXT\
**Others:** HTML

## Getting Started with Aspose.Tasks for C++

Are you ready to give Aspose.Tasks for C++ a try? Simply execute `Install-Package Aspose.Tasks.Cpp` from Package Manager Console in Visual Studio to fetch the NuGet package. If you already have Aspose.Tasks for C++ and want to upgrade the version, please execute `Update-Package Aspose.Tasks.Cpp` to get the latest version.

### Convert Microsoft Project MPP Data to HTML

Try executing the below code to see how Aspose.Tasks for C++ performs in your environment. You may also check the [GitHub Repository](https://github.com/aspose-tasks/Aspose.Tasks-for-C) for other common usage scenarios. 

```c++
System::SharedPtr<Project> project = System::MakeObject<Project>(u"template.mpp");
System::SharedPtr<HtmlSaveOptions> option = System::MakeObject<HtmlSaveOptions>();
project->Save(u"output.html", option);
```

### Create Project from Scratch using C++

Following code sample shows how to create a project file using C++ and then create a task and a sub-task within that project:

```c++
// Create project instance
System::SharedPtr<Project> project = System::MakeObject<Project>();

// Add task, sub task and save project
System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Summary1");
System::SharedPtr<Task> subtask = task->get_Children()->Add(u"Subtask1");
project->Save(u"output.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
```

## Limitations

- No support for printing of any kind.
- No support for Project Online (PWA).
- No support for the database I/O access of any kind.
- No support for EMF/WMF format, neither itself nor as Project file inclusions.

[Product Page](https://products.aspose.com/tasks/cpp) | [Docs](https://docs.aspose.com/display/taskscpp/Home) | [Demos](https://products.aspose.app/tasks/family) | [API Reference](https://apireference.aspose.com/tasks/cpp) | [Examples](https://github.com/aspose-tasks/Aspose.Tasks-for-C) | [Blog](https://blog.aspose.com/category/tasks/) | [Free Support](https://forum.aspose.com/c/tasks) | [Temporary License](https://purchase.aspose.com/temporary-license)

