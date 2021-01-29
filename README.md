# C++ Microsoft Project File Parsing API

[Aspose.Tasks for C++](https://products.aspose.com/Tasks/cpp) library allows the developers to add Tasks generation & recognition capabilities to their own C++ applciations.

Aspose.Tasks for C++ offers Project management APIs that enable C++ applications to not only read and manipulate Microsoft Project&#174; documents, but also write Microsoft Project&#174; documents in both MPP and XML formats - all without using Microsoft Project&#174; itself.

<p align="center">
<a title="Download complete Aspose.Tasks for C++ source code" href="https://github.com/aspose-Tasks/Aspose.Tasks-for-C/archive/master.zip">
<img src="https://raw.github.com/AsposeExamples/java-examples-dashboard/master/images/downloadZip-Button-Large.png" />
</a>
</p>

## Project File Processing via C++

- Convert project data to other [supported file formats](https://docs.aspose.com/tasks/cpp/supported-file-formats/).
- [Create an empty project file](https://docs.aspose.com/tasks/cpp/creating-and-saving/) and save it as XML, to stream or to Microsoft Project format.
- Supports [encoding of the `MPX` files](https://docs.aspose.com/tasks/cpp/reading-project/).
- [Read and write default properties of projects](https://docs.aspose.com/tasks/cpp/default-project-properties/) to speed up the project setup.
- [Set the project calculation mode](https://docs.aspose.com/tasks/cpp/project-calculation-modes/) to be manual, automatic or none.
- Read and write project calendar properties, such as, fiscal year and weekday properties.
- Perform project rescheduling from start, finish date or reschedule only the incomplete tasks.
- Offers various [project utility features](https://docs.aspose.com/tasks/cpp/utility-features/), such as, calculate critical path, read filter data, extract embedded objects etc.
- Use Task, Resource and Project fields as a [formula in expressions](https://docs.aspose.com/tasks/cpp/formula-expressions/).
- Identify Cross Project Tasks, get [predecessor tasks](https://docs.aspose.com/tasks/cpp/predecessor-and-successor-tasks/) and [cross project predecessor](https://docs.aspose.com/tasks/cpp/cross-project-predecessors/) tasks.
- Supports working with task links, baselines & [project resources](https://docs.aspose.com/tasks/cpp/adding-resources/).

## Read & Write Project Files

**Microsoft Project®:** MPP, MPT, MPX, XML

## Save Project Data As

**Primavera:** P6 XML, PM XER\
**Microsoft Excel®:** XLSX\
**Fixed Layout:** PDF\
**Images:** JPEG, PNG, TIF, SVG\
**Text:** TXT\
**Others:** HTML

## Get Started with Aspose.Tasks for C++

Are you ready to give Aspose.Tasks for C++ a try? Simply execute `Install-Package Aspose.Tasks.Cpp` from Package Manager Console in Visual Studio to fetch the NuGet package. If you already have Aspose.Tasks for C++ and want to upgrade the version, please execute `Update-Package Aspose.Tasks.Cpp` to get the latest version.

## Convert Microsoft Project MPP Data to HTML

```c++
System::SharedPtr<Project> project = System::MakeObject<Project>(u"template.mpp");
System::SharedPtr<HtmlSaveOptions> option = System::MakeObject<HtmlSaveOptions>();
project->Save(u"output.html", option);
```

## Create Project from Scratch

```c++
// create project instance
System::SharedPtr<Project> project = System::MakeObject<Project>();

// add task, sub task and save project
System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Summary1");
System::SharedPtr<Task> subtask = task->get_Children()->Add(u"Subtask1");
project->Save(u"output.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
```

[Home](https://www.aspose.com/) | [Product Page](https://products.aspose.com/tasks/cpp) | [Docs](https://docs.aspose.com/tasks/cpp/) | [Demos](https://products.aspose.app/tasks/family) | [API Reference](https://apireference.aspose.com/tasks/cpp) | [Examples](https://github.com/aspose-tasks/Aspose.Tasks-for-C) | [Blog](https://blog.aspose.com/category/tasks/) | [Free Support](https://forum.aspose.com/c/tasks) | [Temporary License](https://purchase.aspose.com/temporary-license)

