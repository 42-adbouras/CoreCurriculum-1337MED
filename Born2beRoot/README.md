# ⚠️ The project is still in progress ⚠️

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
  * What is LVM
  * LVM components
- [Linux File System](#linux-file-system)
  * What is a File System
  * Types of file systems
  * Directory Structure
  * What is Mounting

## Virtuallization
  * What is a Virtual Machine:\
    A virtual machine (VM) is a software emulation of a computer system. It operates based on the architecture and functions of a real or physical computer. VMs run applications and operating systems just like a physical computer. They allow multiple virtual machines to run on a single physical machine, sharing its resources such as CPU, memory, and storage. This enables efficient utilization of hardware and provides flexibility and isolation for running different operating systems and applications.
    
  * Advantages of a Virtual Machine:\
    `Resource Efficiency:` VMs allow multiple operating systems to run on a single physical machine, sharing resources efficiently.\
    `Isolation:` Each VM operates independently, which means that issues in one VM do not affect others.\
    `Flexibility:` VMs can be easily created, modified, or deleted without impacting the host system or other VMs.\
    `Testing and Development:` VMs provide a safe environment for testing new software or configurations without risking the host system.\
    `Disaster Recovery:` VMs can be backed up and restored quickly, which is crucial for business continuity and data recovery.\
    `Scalability:` VMs can be easily scaled up or down to meet changing demands.\
    `Cost Savings:` By consolidating multiple servers onto a single physical machine, VMs can reduce hardware costs.\
    `Portability:` VMs can be moved between different physical machines with minimal disruption.

  * Types of virtuallization:\
    There are two main types of virtualization:\
      `1. Hardware Virtualization:` Also known as Bare Metal, this involves creating a virtual version of an entire computer system, including the hardware. It allows multiple operating systems to run on a single physical machine, each with its own virtual hardware.\
      `2. Operating System Virtualization:` This involves running multiple isolated instances of an operating system on a single host, sharing the host's kernel but having separate user spaces. Containers are more lightweight than VMs and are often used for deploying applications.

    <p align="center">
    <img src="https://www.interviewbit.com/blog/wp-content/uploads/2022/05/Hypervisors-1024x955.png" style="width:500px">
    </p>

  * System Administration:\
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
    Here's a brief overview of LVM components and concepts:\
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

## Linux File System
  * What is a File System:\
    In Linux, a file system is a method of storing and organizing files on a storage device, such as a hard disk, solid-state drive, or network storage. It defines how data is stored, retrieved, and managed on the device. The file system is responsible for keeping track of files, directories, and the space on the disk. It provides a structure that allows users and applications to read from and write to files in a way that is efficient and organized.

  * Types of file systems:\
    Linux supports a variety of file systems, each with its own set of features and capabilities. Some of the most commonly used file systems in Linux includes:\
    `ext, ext2, ext3 and ext4:` The file system Ext stands for Extended File System. It was primarily developed for MINIX OS. The ext file system is an older version, and is no longer used due to some limitations.\
Ext2 is the first Linux file system that allows managing two terabytes of data. Ext3 is developed through Ext2; it is an upgraded version of Ext2 and contains backward compatibility. The major drawback of Ext3 is that it does not support servers because this file system does not support file recovery and disk snapshot.\
Ext4 file system is the faster file system among all the Ext file systems. It is a very compatible option for the SSD (solid-state drive) disks, and it is the default file system in Linux distribution.\
    `FAT32 and NTFS:` These are file systems commonly used in Windows environments but can also be used in Linux for compatibility with removable storage devices.\
    `JFS:` JFS stands for Journaled File System, and it is developed by IBM for AIX Unix. It is an alternative to the Ext file system. It can also be used in place of Ext4, where stability is needed with few resources. It is a handy file system when CPU power is limited.\
    `Swap:` The swap file system is used for memory paging in Linux operating system during the system hibernation. A system that never goes in hibernate state is required to have swap space equal to its RAM size.\
    `etc.:` There is much more to filesystems, if you want to dive deeper, [here](https://www.javatpoint.com/linux-file-system) is a good source.

    In summory, you can say that a file system is a flag, telling the operation system what kind of driver to load, to read, write in a drive or partition.
    
  * Directory Structure:\
    The Linux directory structure is a hierarchical organization of files and directories that defines how data is stored and accessed on a Linux system. It's designed to make it easy for users and applications to find and access files. Here's a brief overview of the main directories in the Linux filesystem:\
    `/:` The root directory, is the top-level directory in the hierarchy. All other directories and files on the system are contained within this directory.\
    `/bin:` Contains essential command binaries that are needed for the system to boot and run. These are basic commands that are available to all users.\
    `/sbin:` Similar to /bin, but contains system binaries that are typically used for system maintenance and administration.\
    `/etc:` Contains system-wide configuration files. This directory is crucial for the configuration of the system and its services.\
    `/home:` Contains user directories. Each user has a directory under /home where their personal files and directories are stored.\
    `/usr:` Contains multi-user utilities and applications. This includes binaries, libraries, and documentation.\
    `/var:` Contains variable data files such as system logs, databases, and mail. This directory can grow in size over time.\
    `/tmp:` A temporary directory used for storing temporary files created by the system and users.\
    `/boot:` Contains files needed to boot the system, including the Linux kernel and initial RAM disk (initrd).\
    `/dev:` Contains device files that represent hardware devices. These files are used by the system to interact with hardware.\
    `/lib and /lib64:` Contain library files that are needed by the system and applications to run.\
    `/opt:` Used for optional or add-on software packages.\
    `/proc:` A virtual filesystem that provides information about the system and running processes.\
    `/sys:` Another virtual filesystem that provides a view into the kernel's view of the system's hardware.\
    `/mnt and /media:` Used for mounting external file systems.

  * What is Mounting:\
      Mounting in Linux is the process of making a file system available for use by attaching it to a specific directory in the existing file system hierarchy. This allows users and applications to access the files and directories on the mounted file system as if they were part of the main file system. The mount command is used to perform this operation, specifying the device and the mount point.




    
