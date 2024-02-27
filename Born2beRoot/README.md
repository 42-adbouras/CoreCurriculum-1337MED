# ⚠️ The project is still in progress ⚠️

## Introduction

The aim of Born2beRoot is to learn and explore the fundamentals of `system administration` and `virtualization` by inviting us to install a `virtual machime` using VirtualBox.
We have to create a server respecting the partition scheme defined in the subject, and we have the right to choose between two Linux distributions (Debian or Rocky).
Here you can find the topics that we will examine, we are going to tackle the configuration of the server, I will not go through the installation.

# ToC

### [Mandatory](#i---mandatory)

- [Virtuallization](#virtuallization)
  * What is a Virtual Machine?
  * Advantages of a Virtual Machine
  * Types of virtuallization
- [LVM](#lvm)
  * What is LVM?
  * LVM components
  * What is encryption?
  * Purpose of sevaral partitions
- [Linux File System](#linux-file-system)
  * What is a File System?
  * Types of file systems
  * Directory Structure
  * What is Mounting?
- [Packet Management in Debian](#packet-management-in-debian)
  * APT
  * Aptitude
  * The diffrence between APT & Aptitude

- [AppArmor](#apparmor)

- [UFW](#ufw)

- [SSH](#ssh)
  * What is SSH?
  * How does SSH works?
 

### [Bonus](#ii---bonus)


# I - Mandatory
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

  * What is encryption:\
    Encryption is the process of converting plain, readable data into an unreadable format using algorithms and keys. This is done to secure the data and prevent unauthorized access, ensuring that only authorized parties with the corresponding decryption keys can access and understand the original information.\
    Based on the subject, when configuring volumes in Linux, particularly with Logical Volume Manager (LVM), the encryption is typically achieved using a software-based encryption mechanism called dm-crypt. dm-crypt is a kernel-level encryption module that provides transparent encryption of block devices, including logical volumes managed by LVM.

  * Purpose of sevaral partitions:\
    We could very well have a single partition to contain all of the operating system’s data, all of the software and all of the personal user files. The purpose of having several distinct partitions is to not put all our eggs in the same basket. If one file system becomes corrupted for example, only one of the partitions would be affected instead of the entire system.\
    In summary, the utilization of multiple partitions provides advantages such as organization, security, multi-boot capability, performance optimization, backup efficiency, and file system flexibility.
    
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

    In summary, you can say that a filesystem serves as a signal or a "flag" to the operating system, indicating which driver to load for reading and writing data on a specific drive or partition.
    
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

## Packet Management in Debian
   In Linux-based operating systems such as Debian, software installation is achieved through packages. These packages encapsulate all the necessary files required for executing a specific set of commands or functionalities. Thus, it's crucial to understand how to install these packages on our Born2beroot virtual machine.
   
  * APT:\
    APT (Advanced Package Tool) is a package management command-line tool used by Debian. It simplifies the process of managing software packages on Linux systems. apt provides a high-level command-line interface for the package management system and is designed to handle the installation, upgrade, and removal of software packages, as well as the management of package dependencies.\
    Here are some of the key functionalities provided by apt:\
`Installing Packages:` You can install new software packages using the `apt install` command.\
`Updating Package Lists:` Before installing new packages, it's a good practice to update the package lists to ensure you're getting the latest versions. This is done with the `apt update` command.\
`Upgrading Packages:` To upgrade all installed packages to their latest versions, you can use the `apt upgrade` command.\
`Removing Packages:` If you no longer need a package, you can remove it using the `apt remove` command.\
`Searching for Packages:` You can search for available packages using the `apt search` command.\
`Cleaning Up:` apt also allows you to clean up unnecessary packages and dependencies that were installed as dependencies but are no longer needed with the `apt autoremove` command.

  * Aptitude:\
    Aptitude also like APT, it's a high-level package management interface for Debian-based systems, it provides a text-based interface similar to a menu-driven package manager, making it more user-friendly for some users who prefer graphical interfaces.
Aptitude can perform most package management tasks, including installing, removing, and upgrading packages, as well as searching for packages and resolving package dependencies.
Aptitude also includes features like package filtering, package previewing, and a powerful dependency resolver.

  * The diffrence between APT & Aptitude:\
    `Interface:` APT primarily offers a command-line interface, whereas Aptitude provides a text-based menu-driven interface.\
`Functionality:` Both tools can perform similar package management tasks, but Aptitude may offer additional features like package filtering and previewing.\
`User Experience:` Aptitude may be preferred by users who are more comfortable with graphical or menu-driven interfaces, while APT may be preferred by those who prefer command-line interfaces.\
`Resource Usage:` Aptitude tends to use slightly more system resources compared to APT due to its interactive interface and additional features.\
In summary, both APT and Aptitude are powerful package management tools in Debian-based Linux distributions, each with its own set of features and interface preferences. Users can choose the tool that best fits their needs and workflow.

## AppArmor
   AppArmor is a Linux security module that restricts the capabilities of individual programs by enforcing security policies, ensuring that programs can only perform actions that are explicitly allowed. It come preinstalled in Debian.\
   AppArmor uses profiles to define the security policies for each program. A profile is a set of rules that specify what actions a program can perform and on which files or directories. Profiles are stored in the `/etc/apparmor.d/` directory.\
   Apparmor has two types of profile modes, `enforced` and `complain`. Profiles in enforcement mode enforce that profile's rules and report violation attempts in `/var/log/syslog`. Profiles in complain mode don't enforce any profile rules, just log violation attempts.
   The `apparmor-utils` package contains command line tools for configuring Apparmor. Using it you can change Apparmor's execution mode, find the status of a profile create new profiles, etc.
   
These are the most common commands:
   * You can check Apparmor's status with `aa-status`.
   * To put a profile in `complain` mode you can use `sudo aa-complain /path/to/profile`, `</path/to/profile>` path where the profile directory is located.
   * To put a profile in `enforced` mode you can use `sudo aa-enforce /path/to/profile`.
   * You can read more over [here](https://askubuntu.com/questions/236381/what-is-apparmor).

## UFW
   

## SSH
  * What is SSH?\
    SSH (Secure Shell) is a cryptographic network protocol used for secure communication over an unsecured network. It provides a secure way to access and manage remote systems or devices over a network, such as the internet. SSH is commonly used for tasks like remote command execution, file transfer, and tunneling network connections.
  * How does SSH works?\
    SSH commonly uses asymmetric encryption as part of its authentication process. Asymmetric encryption, also known as public-key cryptography, works with a pair of cryptographic keys: a `public key` and a `private key`.\
    The public key is used to encrypt data, while the private key is used to decrypt it. Messages encrypted with the public key can only be decrypted with the corresponding private key, ensuring secure communication without the need to share secret keys.
<p align="center">
<img src="https://www.hostinger.com/tutorials/wp-content/uploads/sites/2/2017/07/asymmetric-encryption.webp" style="width:600px">
</p>

  * You can read more over [here](https://www.hostinger.com/tutorials/ssh-tutorial-how-does-ssh-work#How_Does_SSH_Work).




# II - Bonus




