# Generated by Django 5.1.5 on 2025-01-20 18:16

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('vidyapath_project', '0002_notice'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='notice',
            name='created_at',
        ),
    ]
