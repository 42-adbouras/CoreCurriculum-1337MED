# The project is still in progress ⚠️

## Introduction

The aim of Born2beRoot is to learn and explore the fundamentals of `system administration` and `virtualization` by inviting us to install a `virtual machime` using VirtualBox.
We have to create a server respecting the partition scheme defined in the subject, and we have the right to choose between two Linux distributions (Debian or Rocky).
Here you can find the topics that we will examine, we are going to tackle the configuration of the server, I will not go through the installation.

# TOC
- [Virtuallization](#virtuallization)
  * What is a Virtual Machine
  * Advantages of a Virtual Machine
  * Types of virtuallization
- [LVM](#lvm)
  * What is LVM:
  * LVM components:


## Virtuallization
  * What is a Virtual Machine:

    A virtual machine (VM) is a software emulation of a computer system. It operates based on the architecture and functions of a real or physical computer. VMs run applications and operating systems just like a physical computer. They allow multiple virtual machines to run on a single physical machine, sharing its resources such as CPU, memory, and storage. This enables efficient utilization of hardware and provides flexibility and isolation for running different operating systems and applications.
    
  * Advantages of a Virtual Machine:

    `Resource Efficiency:` VMs allow multiple operating systems to run on a single physical machine, sharing resources efficiently.\
    `Isolation:` Each VM operates independently, which means that issues in one VM do not affect others.\
    `Flexibility:` VMs can be easily created, modified, or deleted without impacting the host system or other VMs.\
    `Testing and Development:` VMs provide a safe environment for testing new software or configurations without risking the host system.\
    `Disaster Recovery:` VMs can be backed up and restored quickly, which is crucial for business continuity and data recovery.\
    `Scalability:` VMs can be easily scaled up or down to meet changing demands.\
    `Cost Savings:` By consolidating multiple servers onto a single physical machine, VMs can reduce hardware costs.\
    `Portability:` VMs can be moved between different physical machines with minimal disruption.

  * Types of virtuallization:

    There are two main types of virtualization:\
      `1. Hardware Virtualization:` Also known as Bare Metal, this involves creating a virtual version of an entire computer system, including the hardware. It allows multiple operating systems to run on a single physical machine, each with its own virtual hardware.\
      `2. Operating System Virtualization:` Also known as containerization, this involves running multiple isolated instances of an operating system on a single host, sharing the host's kernel but having separate user spaces. Containers are more lightweight than VMs and are often used for deploying applications.

    <p align="center">
    <img src="https://www.interviewbit.com/blog/wp-content/uploads/2022/05/Hypervisors-1024x955.png" style="width:500px">
    </p>

  * _System Administration:_\
    System administration is the practice of managing and maintaining computer systems, networks, and services. It involves a variety of tasks, including:\
    Installing and configuring hardware and software.\
    Managing user accounts and permissions.\
    Ensuring system security and compliance with policies.\
    Monitoring system performance and availability.\
    Troubleshooting and resolving technical issues.\
    Planning for system growth and capacity.\
    Keeping systems up-to-date with the latest patches and updates.\
    Sstem administrators are responsible for the smooth operation of IT infrastructure and are often the first point of contact for technical issues within an organization.
    
## LVM
  * What is LVM:\
    LVM, or Logical Volume Management, is a method of disk management that allows for the flexible allocation of disk space to logical volumes. Unlike traditional disk partitioning, which divides a physical disk into fixed-size partitions, LVM allows for the creation of logical volumes that can span multiple physical disks. This flexibility enables easier disk space management, including resizing, moving, and snapshotting of volumes.

  * LVM components:\
    Here's a brief overview of LVM components and concepts:
`1. Physical Volumes (PVs):` These are the actual physical disks or partitions that are used by LVM. They are the lowest level of storage in LVM.\
`2. Volume Groups (VGs):` A volume group is a collection of one or more physical volumes that are combined to form a single logical unit. VGs are used to allocate disk space to logical volumes.\
`3. Logical Volumes (LVs):` These are the virtual partitions created within a volume group. They can be resized, moved, and snapshotted independently of the physical storage.\
`4. Physical Extents (PEs):` The smallest unit of disk space that can be allocated to a logical volume. A physical volume is divided into physical extents, which are then used to create logical volumes.\
`5. Snapshots:` LVM allows for the creation of snapshots of logical volumes. A snapshot is a point-in-time copy of a logical volume, which can be used for backup or testing purposes.\
`6. Striping:` LVM supports striping, which is the process of splitting data across multiple physical volumes to improve performance. This can be done at the volume level or within a single logical volume.\
`7. Mirroring:` LVM can also mirror data across multiple physical volumes to provide redundancy and improve data integrity.

    <p align="center">
    <img src="https://www.redhat.com/sysadmin/sites/default/files/styles/full/public/2020-03/LVM%20Cropped.jpg?itok=wz2G1Aci" style="width:600px">
    </p>
